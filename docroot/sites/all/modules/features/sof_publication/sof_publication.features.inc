<?php
/**
 * @file
 * sof_publication.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_publication_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sof_publication_node_info() {
  $items = array(
    'publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => t('Use this page for publishing publications to the publication directory.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
