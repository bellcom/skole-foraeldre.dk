<?php
/**
 * @file
 * sof_question_and_answers.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sof_question_and_answers_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['sof_qa_search-sof_qa_search'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'sof_qa_search',
    'module' => 'sof_qa_search',
    'node_types' => array(),
    'pages' => 'qa/*',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven_subtheme',
        'weight' => 0,
      ),
      'sof_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'sof_theme',
        'weight' => -35,
      ),
    ),
    'title' => 'Search',
    'visibility' => 1,
  );

  $export['views-qa_related_questions-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'qa_related_questions-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven_subtheme',
        'weight' => 0,
      ),
      'sof_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sof_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
