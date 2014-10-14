<?php
/**
 * @file
 * sof_file_types.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sof_file_types_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'file-audio-field_folder'
  $field_instances['file-audio-field_folder'] = array(
    'bundle' => 'audio',
    'cardinality' => 1,
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'file',
    'field_name' => 'field_folder',
    'label' => 'Media Folder',
    'required' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'media_folders',
          'parent' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'type' => 'taxonomy_term_reference',
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'file-document-field_folder'
  $field_instances['file-document-field_folder'] = array(
    'bundle' => 'document',
    'cardinality' => 1,
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'file',
    'field_name' => 'field_folder',
    'label' => 'Media Folder',
    'required' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'media_folders',
          'parent' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'type' => 'taxonomy_term_reference',
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'file-image-field_file_image_alt_text'
  $field_instances['file-image-field_file_image_alt_text'] = array(
    'bundle' => 'image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Alternative text is used by screen readers, search engines, and when the image cannot be loaded. By adding alt text you improve accessibility and search engine optimization.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'file',
    'field_name' => 'field_file_image_alt_text',
    'label' => 'Alt Text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'file-image-field_file_image_title_text'
  $field_instances['file-image-field_file_image_title_text'] = array(
    'bundle' => 'image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Title text is used in the tool tip when a user hovers their mouse over the image. Adding title text makes it easier to understand the context of an image and improves usability.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'file',
    'field_name' => 'field_file_image_title_text',
    'label' => 'Title Text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'file-image-field_folder'
  $field_instances['file-image-field_folder'] = array(
    'bundle' => 'image',
    'cardinality' => 1,
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'file',
    'field_name' => 'field_folder',
    'label' => 'Media Folder',
    'required' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'media_folders',
          'parent' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'type' => 'taxonomy_term_reference',
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'file-video-field_folder'
  $field_instances['file-video-field_folder'] = array(
    'bundle' => 'video',
    'cardinality' => 1,
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'file',
    'field_name' => 'field_folder',
    'label' => 'Media Folder',
    'required' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'media_folders',
          'parent' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'type' => 'taxonomy_term_reference',
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alt Text');
  t('Alternative text is used by screen readers, search engines, and when the image cannot be loaded. By adding alt text you improve accessibility and search engine optimization.');
  t('Media Folder');
  t('Title Text');
  t('Title text is used in the tool tip when a user hovers their mouse over the image. Adding title text makes it easier to understand the context of an image and improves usability.');

  return $field_instances;
}
