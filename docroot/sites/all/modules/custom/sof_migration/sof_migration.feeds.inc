<?php

/**
 * @file
 * Feeds mapper for SOF migration module.
 *
 * @author Dobrin Dobrev <ddobrev@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 */
function sof_migration_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  $info = entity_get_info($entity_type);

  if ($entity_type === 'node') {
    $targets['user_sitecore'] = array(
      'name' => t('User from Sitecore'),
      'callback' => 'sof_migration_user_sitecore_set_target',
      'description' => t('User from Sitecore ident.'),
    );
  }

  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);

    if (in_array($info['type'], array('file', 'image'))) {
      $targets["$name:sc-guid"] = array(
        'name' => t('@label: Sitecore GUID', array('@label' => $instance['label'])),
        'callback' => 'sof_migration_file_guid_set_target',
        'description' => t('The file GUID of the @label field.', array('@label' => $instance['label'])),
        'real_target' => $name,
      );
    }

    if ($info['type'] == 'entityreference') {
      // Currently works only for nodes of type faq_qa, factbox.
      $targets["$name:sc-guid"] = array(
        'name' => t('@label: Sitecore GUID', array('@label' => $instance['label'])),
        'callback' => 'sof_migration_entity_guid_set_target',
        'description' => t('The node GUID of the @label field.', array('@label' => $instance['label'])),
        'real_target' => $name,
      );
    }

    if ($info['type'] == 'link_field') {
      $targets["$name:sc-url"] = array(
        'name' => t('@name: Sitecore URL', array('@name' => $instance['label'])),
        'callback' => 'sof_migration_link_set_target',
        'description' => t('The @label field of the entity.', array('@label' => $instance['label'])),
        'real_target' => $name,
      );
    }
  }
}

/**
 * Callback for UUID mapping.
 */
function sof_migration_user_sitecore_set_target($source, $entity, $target, array $values) {
  $entity->uid = 0;

  $ident = reset($values);
  if ($ident) {
    if (preg_match('/^' . preg_quote('sitecore\\') . '(.+)$/', $ident, $matches)) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'user');
      $query->propertyCondition('mail', "$matches[1]@", 'STARTS_WITH');
      $query->range(0, 1);
      $result = $query->execute();

      if ($result) {
        if (isset($result['user'])) {
          $uids = array_keys($result['user']);
          $entity->uid = reset($uids);
        }
      }
    }
  }
}

/**
 * Map file by file entity guid.
 */
function sof_migration_file_guid_set_target($source, $entity, $target, array $values) {
  list($field_name) = explode(':', $target);

  $field = isset($entity->$field_name) ? $entity->$field_name : array(LANGUAGE_NONE => array());
  foreach ($values as $guids) {
    if ($guids) {
      foreach (explode('}|{', $guids) as $guid) {
        $fid = db_select('feeds_item')
          ->fields('feeds_item', array('entity_id'))
          ->condition('entity_type', 'file')
          ->condition('guid', $guid)
          ->execute()
          ->fetchField();

        if (!$fid) {
          // @TODO - Possibly remove later.
          // TODO: What would we do with this one?
          drupal_set_message(t('Sitecore file ID ({@guid}) could not be found!', array('@guid' => $guid)), 'error');
          watchdog('Sitecore Migrate', "Sitecore file ID ({$guid}) could not be found!", array(), WATCHDOG_ERROR);
        }

        $file = file_load($fid);
        if ($fid && $file) {
          $field[LANGUAGE_NONE][] = array(
            'fid' => $file->fid,
            // Required for files. Flag "whether to display".
            'display' => 1,
          );
        }
      }
    }
  }

  $entity->$field_name = $field;
}

/**
 * Map related content by node entity guid.
 */
function sof_migration_entity_guid_set_target($source, $entity, $target, array $values) {
  list($field_name) = explode(':', $target);

  $field = isset($entity->$field_name) ? $entity->$field_name : array(LANGUAGE_NONE => array());
  foreach ($values as $guids) {
    if ($guids) {
      foreach (explode('}|{', $guids) as $guid) {
        $query = db_select('feeds_item', 'f');
        $query->innerJoin('node', 'n', 'n.nid = f.entity_id');
        $nid = $query
          ->fields('f', array('entity_id'))
          ->condition('f.entity_type', 'node')
          // Hardcoded. May need to add form setting.
          ->condition('n.type', array('faq_qa', 'factbox'))
          ->condition('f.guid', $guid)
          ->execute()
          ->fetchField();

        $node = node_load($nid);
        if ($nid && $node) {
          $field[LANGUAGE_NONE][] = array(
            'target_id' => $node->nid,
          );
        }
      }
    }
  }

  $entity->$field_name = $field;
}

/**
 * Map Sitecore links to drupal links field.
 */
function sof_migration_link_set_target($source, $entity, $target, array $values) {
  module_load_include('inc', 'sof_migration', 'include/misc');
  list($field_name) = explode(':', $target);

  $field = isset($entity->$field_name) ? $entity->$field_name : array(LANGUAGE_NONE => array());

  foreach ($values as $value) {
    if ($value) {
      $doc = new DOMDocument();
      $doc->loadXML($value);
      $xpath = new DOMXpath($doc);

      foreach ($xpath->query('//link') as $link) {
        $linktype = $link->getAttribute('linktype');
        $linkvalue = array(
          'title' => $link->getAttribute('text'),
          'url' => $link->getAttribute('url'),
        );
        switch ($linktype) {
          case 'internal':
          case 'media':
            $uuid = $link->getAttribute('id');
            $uuid = trim($uuid, '{}');
            $uuid = strtolower($uuid);
            $nids = entity_get_id_by_uuid('node', array($uuid));
            $fids = entity_get_id_by_uuid('file', array($uuid));
            if ($linktype === 'internal' && $nids) {
              $nid = reset($nids);
              $linkvalue['url'] = "node/$nid";
            }
            elseif ($linktype === 'media' && $fids) {
              $fid = reset($fids);
              $linkvalue['url'] = sof_migration_file_download_url($fid);
              $linkvalue['attributes']['target'] = '_blank';
            }
            break;

          case 'external':
          default:
            // Do nothing. Link is already correctly set above.
            break;
        }
        $field[LANGUAGE_NONE][] = $linkvalue;
      }
    }
  }

  $entity->$field_name = $field;
}

/**
 * Callback for exploding string and getting terms.
 */
function sof_migration_explode_terms_set_target($source, $entity, $target, array $values, $mapping = array()) {
  $glue = ' ';
  $string = implode($glue, $values);
  $terms = explode($glue, $string);
  $terms = array_map('trim', $terms);
  $terms = array_filter($terms);
  preg_match('/^(.+):explode-string$/', $target, $fieldname);

  return taxonomy_feeds_set_target($source, $entity, $fieldname[1], $terms, $mapping);
}
