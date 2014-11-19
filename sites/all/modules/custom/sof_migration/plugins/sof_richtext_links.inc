<?php

/**
 * @file
 * Fix SOF richtext links.
 */

$plugin = array(
  'form' => 'sof_richtext_links_form',
  'callback' => 'sof_richtext_links_callback',
  'name' => 'Fix SOF richtext links',
  'multi' => 'loop',
  'category' => 'SOF',
);

function sof_richtext_links_form($importer, $element_key, $settings) {
  $form = array();
  $form['help'] = array(
    '#markup' => t('Nothing to configure.'),
  );
  return $form;
}

function sof_richtext_links_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  preg_match_all('#<a href="(~/media/([^\.]+)\.ashx)">[^<]+</a>#', $field, $link_matches);
  if ($link_matches[2]) {
    foreach ($link_matches[2] as $key => $guid_no_dash) {
      $guid = preg_replace('/^(.{8})(.{4})(.{4})(.{4})(.*)$/', '{$1-$2-$3-$4-$5}', $guid_no_dash);
      $guid = trim($guid, '{}');
      $guid = strtolower($guid);
      if ($fids = entity_get_id_by_uuid('file', array($guid))) {
        $fid = reset($fids);
        $file = file_load($fid);
        $uri = file_entity_download_uri($file);
        $url = url($uri['path'], $uri['options'] + array('absolute' => TRUE));
        $field = preg_replace('#(<a href=")~/media/[^\.]+\.ashx(">[^<]+</a>)#', "\${1}{$url}\${2}", $field);
        // When using PREG_OFFSET_CAPTURE
        // $replaced = substr_replace($field, $url, $link_matches[1][$key][1], strlen($link_matches[1][$key][0]));
//        dpm($replaced, '$replaced');
//        dpm($uri, '$uri');
//        dpm($guid, '$guid');
//        dpm($entities, '$entities');
//        dpm($link_matches, '$link_matches');
      }
    }
  }
}
