<?php
/**
 * @file
 * sof_question_and_answers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_question_and_answers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sof_question_and_answers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sof_question_and_answers_node_info() {
  $items = array(
    'question_and_answer' => array(
      'name' => t('Question and Answer'),
      'base' => 'node_content',
      'description' => t('Use this page for publishing QA content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
