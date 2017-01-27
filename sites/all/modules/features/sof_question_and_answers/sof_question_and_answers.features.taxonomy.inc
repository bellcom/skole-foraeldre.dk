<?php
/**
 * @file
 * sof_question_and_answers.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sof_question_and_answers_taxonomy_default_vocabularies() {
  return array(
    'qa_category' => array(
      'name' => 'QA Category',
      'machine_name' => 'qa_category',
      'description' => 'Use the category for Question and Answer',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
