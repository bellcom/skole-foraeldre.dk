<?php

/**
 * @file
 * Miscellaneous.
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

    if ($nids = entity_get_id_by_uuid('node', array($uuid))) {
      $return['nid'] = reset($nids);
    }

    if ($fids = entity_get_id_by_uuid('file', array($uuid))) {
      $return['fid'] = reset($fids);
    }
  }

  return $return;
}

//function sof_migration_file_download_url($fid, $raw = TRUE) {
//  $file = file_load($fid);
//  $uri = file_entity_download_uri($file);
//
//  if ($raw) {
//    return $uri['path'] . '?token=' . rawurlencode($uri['options']['query']['token']);
//  }
//
//  // Just for clarity - this is not an absolute URL.
//  $uri['options']['absolute'] = FALSE;
//  return url($uri['path'], $uri['options']);
//}

function sof_migration_get_links_map() {
  static $links;

  if (!isset($links)) {
    $links_map_file = drupal_realpath('public://import/misc/links-custom-map.php');
    require $links_map_file;
    $links = $export;
  }

  return $links;
}
