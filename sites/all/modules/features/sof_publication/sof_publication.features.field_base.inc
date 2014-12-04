<?php
/**
 * @file
 * sof_publication.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sof_publication_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_sof_commerce_product'
  $field_bases['field_sof_commerce_product'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sof_commerce_product',
    'foreign keys' => array(
      'product_id' => array(
        'columns' => array(
          'product_id' => 'product_id',
        ),
        'table' => 'commerce_product',
      ),
    ),
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_product_reference',
    'settings' => array(
      'options_list_limit' => '',
    ),
    'translatable' => 0,
    'type' => 'commerce_product_reference',
  );

  return $field_bases;
}
