<?php
/**
 * @file
 * sof_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sof_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'general_category' => array(
      'name' => 'General category',
      'machine_name' => 'general_category',
      'description' => 'Use the category to group postings on similar topics into a main category used for relating content.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'base_i18n_mode' => 0,
      'base_language' => 'und',
    ),
    'magazine_categories' => array(
      'name' => 'Magazine categories',
      'machine_name' => 'magazine_categories',
      'description' => 'Use for categorizing titles on the magazine deck',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'base_i18n_mode' => 0,
      'base_language' => 'und',
    ),
    'media_folders' => array(
      'name' => 'Media Folders',
      'machine_name' => 'media_folders',
      'description' => 'Use media folders to organize your media',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'base_i18n_mode' => 0,
      'base_language' => 'und',
    ),
    'publication_category' => array(
      'name' => 'Publication category',
      'machine_name' => 'publication_category',
      'description' => 'Use this categroy to group publications on similar topics.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'base_i18n_mode' => 0,
      'base_language' => 'und',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'base_i18n_mode' => 0,
      'base_language' => 'und',
    ),
  );
}
