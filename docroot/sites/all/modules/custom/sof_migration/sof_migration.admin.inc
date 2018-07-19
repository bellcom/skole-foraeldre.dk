<?php

/**
 * @file
 * SOF migration module admin pages.
 *
 * @author Dobrin Dobrev <ddobrev@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

/**
 * Form to start batch to fix migrated links.
 */
function sof_migration_post_migrate($form, &$form_state) {
  $form['fix_links'] = array(
    '#submit' => array('sof_migration_fix_links_submit'),
    '#type' => 'submit',
    '#value' => 'Fix links',
  );

  return $form;
}

/**
 * Submit handler.
 *
 * @param array $form
 *   Should be filled with proper information.
 * @param array $form_state
 *   Should be filled with proper information.
 *
 * @return array
 *   Should be filled with proper information.
 */
function sof_migration_fix_links_submit(&$form, &$form_state) {
  $batch = array(
    'operations' => array(
      array(
        'sof_migration_fix_links_batch',
        array(
          'some batch data',
          'more batch data',
        ),
      ),
    ),
    'finished' => 'sof_migration_fix_links_batch_finished',
    'title' => t('Fixing links'),
    'init_message' => t('Preparing to fix SOF migration links...'),
    'progress_message' => t('Fixing SOF migration links...'),
    'error_message' => t('There was an error while fixing SOF migration links.'),
    'file' => drupal_get_path('module', 'sof_migration') . '/sof_migration.admin.inc',
  );

  batch_set($batch);
}

/**
 * Batch operation 1.
 *
 * @param array $arg1
 *   Should be filled with proper information.
 * @param array $arg2
 *   Should be filled with proper information.
 * @param array $context
 *   Should be filled with proper information.
 *
 * @return array
 *   Should be filled with proper information.
 */
function sof_migration_fix_links_batch($arg1, $arg2, &$context) {
  if (empty($context['sandbox'])) {
    $efq = new EntityFieldQuery();
    $efq->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', array('article', 'news'))
      ->propertyCondition('status', 1);

    $result = $efq->execute();

    if (!empty($result)) {
      foreach ($result as $k => $v) {
        foreach ($v as $k1 => $v1) {
          $node_data[] = $v1->nid;
        }
      }
    }
    else {
      drupal_set_message(t('No nodes found. Aborting!'), 'error');
    }

    $context['sandbox']['progress'] = 0;
    $context['sandbox']['submitted'] = 0;
    $context['sandbox']['max'] = count($node_data);
    $context['sandbox']['nids'] = $node_data;
  }

  // The format is {5B8291BB-6CF0-4D89-A907-F5B4F3E25C5F} stripped from -{}.
  $lenght_of_sitecore_id = 32;

  $limit = 30;
  $count = min($limit, count($context['sandbox']['nids']));
  for ($i = 1; $i <= $count; $i++) {
    $nid = array_shift($context['sandbox']['nids']);
    $node = node_load($nid);
    $update_node = FALSE;

    $markup = $node->body[LANGUAGE_NONE][0]['value'];
    preg_match_all('/ href="([^"]+)"/', $markup, $href_matches);
    foreach ($href_matches[1] as $href_match) {
      // Load again in case there are multiple links to be fixed in a node.
      $node = node_load($nid);
      $markup = $node->body[LANGUAGE_NONE][0]['value'];
      $links_map_link = html_entity_decode($href_match);

      // Remove domain url.
      if (strpos($links_map_link, $GLOBALS['base_url'] . '/') === 0) {
        $links_map_link = substr($links_map_link, strlen($GLOBALS['base_url'] . '/'));
      }

      // Fix links to internal content.
      if (strpos($links_map_link, '~/link.aspx?_id=') !== FALSE) {
        $link_id = substr($links_map_link, strlen('~/link.aspx?_id='), $lenght_of_sitecore_id);
        $formatted_link_id = sof_migration_format_id($link_id);
        $nid1 = entity_get_id_by_uuid('node', array($formatted_link_id));
        if ($nid1) {
          $fixed_markup = str_replace(' href="' . $href_match . '"', ' href="' . url("node/{$nid1[$formatted_link_id]}") . '"', $markup);
          if ($fixed_markup !== $markup) {
            $node->body[LANGUAGE_NONE][0]['value'] = $fixed_markup;
            node_save($node);

            $message = t('Link ID is @link_id! Fixed link in node/@node_nid!', array('@link_id' => $link_id, '@node_nid' => $node->nid));
            drupal_set_message($message, 'status');
          }
        }
      }

      // Fix file links.
      if (strpos($links_map_link, '~/media/') !== FALSE) {
        $link_id = substr($links_map_link, strlen('~/media/'), $lenght_of_sitecore_id);
        $formatted_file_id = sof_migration_format_id($link_id);
        $fid = entity_get_id_by_uuid('file', array($formatted_file_id));
        if ($fid) {
          $fixed_markup = str_replace(' href="' . $href_match . '"', ' href="' . sof_migration_file_download_url($fid[$formatted_file_id], FALSE) . '"', $markup);
          if ($fixed_markup !== $markup) {
            $node->body[LANGUAGE_NONE][0]['value'] = $fixed_markup;
            node_save($node);

            $message = t('Link ID is @link_id! Fixed file link in node/@node_nid!', array('@link_id' => $link_id, '@node_nid' => $node->nid));
            drupal_set_message($message, 'status');
          }
        }
      }
    }

    // Update our progress information.
    $context['sandbox']['progress']++;
  }

  if (empty($context['sandbox']['nids']) || ($context['sandbox']['progress'] === $context['sandbox']['max'])) {
    $context['sandbox']['progress'] = $context['sandbox']['max'];
  }

  $arguments = array(
    '@current' => $context['sandbox']['progress'],
    '@total' => $context['sandbox']['max'],
  );
  $context['message'] = t('Fixing links for @current of @total nodes.', $arguments);

  // Inform the batch engine that we are not finished, and provide an
  // estimation of the completion level we reached.
  $context['finished'] = empty($context['sandbox']['max']) ? 1 : $context['sandbox']['progress'] / $context['sandbox']['max'];

  // Put the total into the results section when we're finished so we can show
  // it to the admin..
  if ($context['finished']) {
    $context['results']['count'] = $context['sandbox']['progress'];
  }
}

/**
 * Finished batch callback.
 *
 * @param array $success
 *   Should be filled with proper information.
 * @param array $results
 *   Should be filled with proper information.
 * @param array $operations
 *   Should be filled with proper information.
 *
 * @return array
 *   Should be filled with proper information.
 */
function sof_migration_fix_links_batch_finished($success, array $results, array $operations) {
  $message = '';

  if (isset($results['count'])) {
    $message .= format_plural($results['count'], '1 nodes processed successfully. ', '@count nodes successfully processed. ');
  }

  if ($success) {
    $type = 'status';
  }
  else {
    // An error occurred. $operations contains the unprocessed operations..
    $error_operation = reset($operations);
    $message .= ' ' . t('An error occurred while processing @num with arguments: @args', array(
      '@num' => $error_operation[0],
      '@args' => print_r($error_operation[0], TRUE),
    ));
    $type = 'error';
  }

  drupal_set_message($message, $type);
}

/**
 * Convert from sitecore format to uuid format.
 *
 * [2282B4E14B6F4AB2BFB3AD71BCD00661] - [2282b4e1-4b6f-4ab2-bfb3-ad71bcd00661]
 */
function sof_migration_format_id($id) {
  $id = strtolower($id);

  $new_id = substr_replace($id, '-', 8, 0);
  $new_id = substr_replace($new_id, '-', 13, 0);
  $new_id = substr_replace($new_id, '-', 18, 0);
  $new_id = substr_replace($new_id, '-', 23, 0);

  return $new_id;
}

/**
 * File download handler.
 *
 * @param int $fid
 *   Should be filled with proper information.
 * @param bool $raw
 *   Should be filled with proper information.
 *
 * @return array
 *   Should be filled with proper information.
 */
function sof_migration_file_download_url($fid, $raw = TRUE) {
  $file = file_load($fid);
  $uri = file_entity_download_uri($file);

  if ($raw) {
    return $uri['path'] . '?token=' . rawurlencode($uri['options']['query']['token']);
  }

  // Just for clarity - this is not an absolute URL..
  $uri['options']['absolute'] = FALSE;

  return url($uri['path'], $uri['options']);
}
