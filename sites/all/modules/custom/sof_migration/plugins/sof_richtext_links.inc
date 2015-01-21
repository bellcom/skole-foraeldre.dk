<?php

/**
 * @file
 * Fix SOF richtext links.
 *
 * @author Dobrin Dobrev <ddobrev@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

/**
 * Plugin with default values.
 */
$plugin = array(
  'form' => 'sof_richtext_links_form',
  'callback' => 'sof_richtext_links_callback',
  'name' => 'Fix SOF richtext links',
  'multi' => 'loop',
  'category' => 'SOF',
);

/**
 * Form plugin.
 *
 * @param array $importer
 *   Should be filled with proper information.
 * @param array $element_key
 *   Should be filled with proper information.
 * @param array $settings
 *   Should be filled with proper information.
 *
 * @return array
 *   The form array.
 */
function sof_richtext_links_form($importer, $element_key, $settings) {
  $form = array();

  $form['help'] = array(
    '#markup' => t('Nothing to configure.'),
  );

  return $form;
}

/**
 * Regular expression matching callback.
 *
 * @param array $result
 *   Should be filled with proper information.
 * @param array $item_key
 *   Should be filled with proper information.
 * @param array $element_key
 *   Should be filled with proper information.
 * @param array $field
 *   Should be filled with proper information.
 * @param array $settings
 *   Should be filled with proper information.
 * @param array $source
 *   Should be filled with proper information.
 */
function sof_richtext_links_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  preg_match_all('#<a href="(~/media/([^\.]+)\.ashx)">[^<]+</a>#', $field, $link_matches);

  if ($link_matches[2]) {
    foreach ($link_matches[2] as $key => $guid_no_dash) {
      $guid = preg_replace('/^(.{8})(.{4})(.{4})(.{4})(.*)$/', '{$1-$2-$3-$4-$5}', $guid_no_dash);
      $guid = trim($guid, '{}');
      $guid = strtolower($guid);
      $fids = entity_get_id_by_uuid('file', array($guid));

      if ($fids) {
        $fid = reset($fids);
        $file = file_load($fid);
        $uri = file_entity_download_uri($file);
        $url = url($uri['path'], $uri['options'] + array('absolute' => TRUE));
        $field = preg_replace('#(<a href=")~/media/[^\.]+\.ashx(">[^<]+</a>)#', "\${1}{$url}\${2}", $field);
      }
    }
  }
}
