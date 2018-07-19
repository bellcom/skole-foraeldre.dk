<?php

/**
 * @file
 * Miscellaneous.
 *
 * @author Dobrin Dobrev <ddobrev@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

/**
 * Gets the entity IDs.
 */
function sof_migration_url_get_entity_ids($url) {
  $links_map = sof_migration_get_links_map();

  $return = array(
    'uuid' => FALSE,
    'nid' => FALSE,
    'fid' => FALSE,
  );

  if (isset($links_map[$url])) {
    $uuid = $links_map[$url];
    $uuid = trim($uuid, '{}');
    $uuid = strtolower($uuid);
    $return['uuid'] = $uuid;

    $nids = entity_get_id_by_uuid('node', array($uuid));
    if ($nids) {
      $return['nid'] = reset($nids);
    }

    $fids = entity_get_id_by_uuid('file', array($uuid));
    if ($fids) {
      $return['fid'] = reset($fids);
    }
  }

  return $return;
}

/**
 * Gets the mapping of the links.
 */
function sof_migration_get_links_map() {
  static $links;

  if (!isset($links)) {
    $links_map_file = drupal_realpath('public://import/misc/links-custom-map.php');
    // TODO: Check with Dobrin what is the idea here.
    require $links_map_file;
    $links = $export;
  }

  return $links;
}
