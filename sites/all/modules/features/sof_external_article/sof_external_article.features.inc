<?php
/**
 * @file
 * sof_external_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_external_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sof_external_article_node_info() {
  $items = array(
    'external_article' => array(
      'name' => t('External Article'),
      'base' => 'node_content',
      'description' => t('Use this page for publishing external articles.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
