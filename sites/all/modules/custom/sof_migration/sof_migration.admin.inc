<?php
/**
 * SOF migration module admin pages.
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
  /*$form['files_make_permanent'] = array(
    '#submit' => array('sof_migration_files_make_permanent_submit'),
    '#type' => 'submit',
    '#value' => 'Make files permanent',
  );*/

  return $form;
}

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

/*
  $efq = new EntityFieldQuery();
  $efq->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'article')
      ->propertyCondition('status', 1);
  $result = $efq->execute();
  if (!empty($result)) {
    foreach ($result as $k => $v) {
      foreach ($v as $k1 => $v1) {
        $node_data[] = node_load($v1->nid);
      }
    }
  }
  else {
    drupal_set_message('No nodes found. Aborting!', 'error');
  }
  //format is {5B8291BB-6CF0-4D89-A907-F5B4F3E25C5F} stripped from -{}
  $lenght_of_sitecore_id = 32;
  foreach ($node_data as $data) {
    $markup = $data->body[LANGUAGE_NONE][0]['value'];
    preg_match_all('/ href="([^"]+)"/', $markup, $href_matches);
    foreach ($href_matches[1] as $href_match) {
      $links_map_link = html_entity_decode($href_match);
      //remove domain url
      if (strpos($links_map_link, $GLOBALS['base_url'] . '/') === 0) {
        $links_map_link = substr($links_map_link, strlen($GLOBALS['base_url'] . '/'));
      }
      //fix links to internal content
      if (strpos($links_map_link, '~/link.aspx?_id=') !== FALSE) {
        $link_id = substr($links_map_link, strlen('~/link.aspx?_id='), $lenght_of_sitecore_id);
        $formatted_link_id = sof_migration_format_id($link_id);
        if ($nid = entity_get_id_by_uuid('node', array($formatted_link_id))) {
          $fixed_markup = str_replace(' href="' . $href_match . '"', ' href="' . url("node/{$nid[$formatted_link_id]}") . '"', $markup);
          if ((strlen($fixed_markup) <> strlen($markup))) {
            $data->body[LANGUAGE_NONE][0]['value'] = $fixed_markup;
            //$data->body[LANGUAGE_NONE][0]['safe_value'] = $fixed_markup;
//            dpm($data, '1');
            node_save($data);
//            dpm($data, '2');
            $message = 'Fixed link in node/' . $data->nid . '!';
            drupal_set_message($message, 'status');
          }
        }
      }
      //fix file links
      if (strpos($links_map_link, '~/media/') !== FALSE) {
        $link_id = substr($links_map_link, strlen('~/media/'), $lenght_of_sitecore_id);
        $formatted_file_id = sof_migration_format_id($link_id);
        if ($fid = entity_get_id_by_uuid('file', array($formatted_file_id))) {
          $fixed_markup = str_replace(' href="' . $href_match . '"', ' href="' . sof_migration_file_download_url($fid[$formatted_file_id], FALSE) . '"', $markup);
          if ($fixed_markup !== $markup) {
            $data->body['und'][0]['value'] = $fixed_markup;
            //node_save($data);
            $message = 'Fixed file link in node/' . $data->nid . '!';
            drupal_set_message($message, 'status');
          }
        }
      }
    }
  }
//  drupal_goto('admin/config/sof-migration/post-migrate');
  */
}


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
      drupal_set_message('No nodes found. Aborting!', 'error');
    }
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['submitted'] = 0;
    $context['sandbox']['max'] = count($node_data);
    $context['sandbox']['nids'] = $node_data;
  }

  //format is {5B8291BB-6CF0-4D89-A907-F5B4F3E25C5F} stripped from -{}
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
      //load again in case there are multiple links to be fixed in a node
      $node = node_load($nid);
      $markup = $node->body[LANGUAGE_NONE][0]['value'];
      
      $links_map_link = html_entity_decode($href_match);
      //remove domain url
      if (strpos($links_map_link, $GLOBALS['base_url'] . '/') === 0) {
        $links_map_link = substr($links_map_link, strlen($GLOBALS['base_url'] . '/'));
      }
      //fix links to internal content
      if (strpos($links_map_link, '~/link.aspx?_id=') !== FALSE) {
        $link_id = substr($links_map_link, strlen('~/link.aspx?_id='), $lenght_of_sitecore_id);
        $formatted_link_id = sof_migration_format_id($link_id);
        if($nid1 = entity_get_id_by_uuid('node', array($formatted_link_id))) {
          $fixed_markup = str_replace(' href="' . $href_match . '"', ' href="' . url("node/{$nid1[$formatted_link_id]}") . '"', $markup);
          if ($fixed_markup !== $markup) {
            $node->body[LANGUAGE_NONE][0]['value'] = $fixed_markup;
            node_save($node);
            $message = 'Link ID is '.$link_id.'! Fixed link in node/' . $node->nid . '!';
            drupal_set_message($message, 'status');
//            drupal_set_message($node->body[LANGUAGE_NONE][0]['value'], 'status');
          }
        }
      }
      //fix file links
      if (strpos($links_map_link, '~/media/') !== FALSE) {
        $link_id = substr($links_map_link, strlen('~/media/'), $lenght_of_sitecore_id);
        $formatted_file_id = sof_migration_format_id($link_id);
        if ($fid = entity_get_id_by_uuid('file', array($formatted_file_id))) {
          $fixed_markup = str_replace(' href="' . $href_match . '"', ' href="' . sof_migration_file_download_url($fid[$formatted_file_id], FALSE) . '"', $markup);
          if ($fixed_markup !== $markup) {
            $node->body[LANGUAGE_NONE][0]['value'] = $fixed_markup;
            node_save($node);
            $message = 'Link ID is '.$link_id.'!Fixed file link in node/' . $node->nid . '!';
            drupal_set_message($message, 'status');
          }
        }
      }
    }
  
    // Fix links.
    /*if (!empty($node->field_links)) {
      foreach ($node->field_links[LANGUAGE_NONE] as $delta => $link) {
        $url = $link['url'];
        $ids = sof_migration_url_get_entity_ids($url);
        if ($ids['uuid']) {
          if ($ids['nid']) {
            $node->field_links[LANGUAGE_NONE][$delta]['url'] = "node/{$ids['nid']}";
            $update_node = TRUE;
          }
          elseif ($ids['fid']) {
            $node->field_links[LANGUAGE_NONE][$delta]['url'] = sof_migration_file_download_url($ids['fid']);
            $node->field_links[LANGUAGE_NONE][$delta]['attributes']['target'] = '_blank';
            $update_node = TRUE;
          }
          else {
            // @TODO - Possibly remove later.
            drupal_set_message("Sitecore GUID ({$ids['uuid']}) could not be found!", 'error');
            watchdog('Sitecore Migrate', "Sitecore GUID ({$ids['uuid']}) could not be found!", array(), WATCHDOG_ERROR);
          }
        }
      }
    }

    if (!empty($node->body)) {
      foreach ($node->body[LANGUAGE_NONE] as $delta => $body) {
        $markup = $body['value'];
        $fixed_markup = sof_migration_markup_fix_links($markup);
        if ($markup !== $fixed_markup) {
          $node->body[LANGUAGE_NONE][$delta]['value'] = $fixed_markup;
          $update_node = TRUE;
        }
      }
    }

    if (!empty($node->field_qa)) {
      foreach ($node->field_qa[LANGUAGE_NONE] as $delta => $collection_value) {
        $collection = field_collection_item_load($collection_value['value']);
        $update_collection = FALSE;

        if (!empty($collection->field_text)) {
          $markup = $collection->field_text[LANGUAGE_NONE][0]['value'];
          $fixed_markup = sof_migration_markup_fix_links($markup);
          if ($markup !== $fixed_markup) {
            $collection->field_text[LANGUAGE_NONE][0]['value'] = $fixed_markup;
            $update_collection = TRUE;
          }
        }

        if ($update_collection) {
          $collection->save(TRUE); // TRUE = Skip host entity save. Save only the collection.
        }
      }
    }*/

    
//    if ($update_node) {
//      node_save($node);
//    }
    
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

  // Inform the batch engine that we are not finished, and provide an estimation of the completion level we reached.
  $context['finished'] = empty($context['sandbox']['max']) ? 1 : $context['sandbox']['progress'] / $context['sandbox']['max'];

  // Put the total into the results section when we're finished so we can show it to the admin.
  if ($context['finished']) {
    $context['results']['count'] = $context['sandbox']['progress'];
  }
}





function sof_migration_fix_links_batch_finished($success, array $results, array $operations) {
  $message = '';
  if (isset($results['count'])) {
    $message .= format_plural($results['count'], '1 nodes processed successfully. ', '@count nodes successfully processed. ');
  }
  if ($success) {
    $type = 'status';
  }
  else {
    // An error occurred. $operations contains the unprocessed operations.
    $error_operation = reset($operations);
    $message .= ' ' . t('An error occurred while processing @num with arguments: @args', array('@num' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE)));
    $type = 'error';
  }
  drupal_set_message($message, $type);
}

/*
function sof_migration_migrated_files_make_permanent_batch($arg1, $arg2, &$context) {
  if (empty($context['sandbox'])) {
    $fids = db_select('feeds_item')
      ->fields('feeds_item', array('entity_id'))
      ->condition('entity_type', 'file')
      ->condition('id', 'import_sof_files')
      ->execute()
      ->fetchCol();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['submitted'] = 0;
    $context['sandbox']['max'] = count($fids);
    $context['sandbox']['fids'] = $fids;
  }

  $limit = 10;
  $count = min($limit, count($context['sandbox']['fids']));
  for ($i = 1; $i <= $count; $i++) {
    // For each fid, load the file.
    $fid = array_shift($context['sandbox']['fids']);
    $file = file_load($fid);

    // Add the usage to prevent automatic file deletion.
    file_usage_add($file, 'sof_migration', 'fake', 1);

    // Update our progress information.
    $context['sandbox']['progress']++;
  }

  if (empty($context['sandbox']['fids']) || ($context['sandbox']['progress'] === $context['sandbox']['max'])) {
    $context['sandbox']['progress'] = $context['sandbox']['max'];
  }

  $arguments = array(
    '@current' => $context['sandbox']['progress'],
    '@total' => $context['sandbox']['max'],
  );
  $context['message'] = t('Made permanent @current of @total files.', $arguments);

  // Inform the batch engine that we are not finished, and provide an estimation of the completion level we reached.
  $context['finished'] = empty($context['sandbox']['max']) ? 1 : $context['sandbox']['progress'] / $context['sandbox']['max'];

  // Put the total into the results section when we're finished so we can show it to the admin.
  if ($context['finished']) {
    $context['results']['count'] = $context['sandbox']['progress'];
  }
}

function sof_migration_files_make_permanent_submit(&$form, &$form_state) {
  $batch = array(
    'operations' => array(
      array(
        'sof_migration_migrated_files_make_permanent_batch',
        array(
          'some batch data',
          'more batch data',
        ),
      ),
    ),
    'finished' => 'sof_migration_migrated_files_make_permanent_batch_finished',
    'title' => t('Making files permanent'),
    'init_message' => t('Preparing to make permanent SOF migrated files...'),
    'progress_message' => t('Making permanent SOF migrated files...'),
    'error_message' => t('There was an error while making SOF migrated files permanent.'),
    'file' => drupal_get_path('module', 'sof_migration') . '/sof_migration.admin.inc',
  );
  batch_set($batch);
}

function sof_migration_migrated_files_make_permanent_batch_finished($success, array $results, array $operations) {
  $message = '';
  if (isset($results['count'])) {
    $message .= format_plural($results['count'], '1 files processed successfully. ', '@count files successfully processed. ');
  }
  if ($success) {
    $type = 'status';
  }
  else {
    // An error occurred. $operations contains the unprocessed operations.
    $error_operation = reset($operations);
    $message .= ' ' . t('An error occurred while processing @num with arguments: @args', array('@num' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE)));
    $type = 'error';
  }
  drupal_set_message($message, $type);
}
*/


/**
 * Pass bad markup returns good markup. The end.
 */
/*
function sof_migration_markup_fix_links($markup) {
  preg_match_all('/ href="([^"]+)"/', $markup, $href_matches);
  foreach ($href_matches[1] as $href_match) {
    $links_map_link = html_entity_decode($href_match);
    if (strpos($links_map_link, $GLOBALS['base_url'] . '/') === 0) {
      $links_map_link = substr($links_map_link, strlen($GLOBALS['base_url'] . '/'));
    }
    $ids = sof_migration_url_get_entity_ids($links_map_link);
    if ($ids['uuid']) {
      if ($ids['nid']) {
        $markup = str_replace(' href="' . $href_match . '"', ' href="' . url("node/{$ids['nid']}") . '"', $markup);
      }
      elseif ($ids['fid']) {
        $markup = str_replace(' href="' . $href_match . '"', ' href="' . sof_migration_file_download_url($ids['fid'], FALSE) . '"', $markup);
      }
      else {
        // @TODO - Possibly remove later.
        drupal_set_message("Sitecore GUID ({$ids['uuid']}) could not be found!", 'error');
        watchdog('Sitecore Migrate', "Sitecore GUID ({$ids['uuid']}) could not be found!", array(), WATCHDOG_ERROR);
      }
    }
  }

  return $markup;
}
*/


/*
 * convert from sitecore format[2282B4E14B6F4AB2BFB3AD71BCD00661] to uuid format [2282b4e1-4b6f-4ab2-bfb3-ad71bcd00661]
 */
function sof_migration_format_id($id) {
  $id = strtolower($id);
  $new_id = substr_replace($id, '-', 8, 0);
  $new_id = substr_replace($new_id, '-', 13, 0);
  $new_id = substr_replace($new_id, '-', 18, 0);
  $new_id = substr_replace($new_id, '-', 23, 0);
  return $new_id;
}


function sof_migration_file_download_url($fid, $raw = TRUE) {
  $file = file_load($fid);
  $uri = file_entity_download_uri($file);

  if ($raw) {
    return $uri['path'] . '?token=' . rawurlencode($uri['options']['query']['token']);
  }

  // Just for clarity - this is not an absolute URL.
  $uri['options']['absolute'] = FALSE;
  return url($uri['path'], $uri['options']);
}