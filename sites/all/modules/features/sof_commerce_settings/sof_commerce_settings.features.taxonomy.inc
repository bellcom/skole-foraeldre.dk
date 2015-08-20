<?php
/**
 * @file
 * sof_commerce_settings.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sof_commerce_settings_taxonomy_default_vocabularies() {
  return array(
    'product_variants' => array(
      'name' => 'Product Variants',
      'machine_name' => 'product_variants',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
