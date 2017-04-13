<?php
/**
 * @file
 * sof_question_and_answers.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sof_question_and_answers_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_answer'.
  $field_bases['field_answer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_answer',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_qa_category'.
  $field_bases['field_qa_category'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_qa_category',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'qa_category',
          'parent' => 0,
        ),
      ),
      'options_list_callback' => 'taxonomy_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
