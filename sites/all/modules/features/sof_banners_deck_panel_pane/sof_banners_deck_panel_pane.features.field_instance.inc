<?php
/**
 * @file
 * sof_banners_deck_panel_pane.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sof_banners_deck_panel_pane_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_banner_collection-field_icon'
  $field_instances['field_collection_item-field_banner_collection-field_icon'] = array(
    'bundle' => 'field_banner_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select icon type for this banner',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'list_key',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_icon',
    'label' => 'Icon',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_banner_collection-field_reference_node'
  $field_instances['field_collection_item-field_banner_collection-field_reference_node'] = array(
    'bundle' => 'field_banner_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Link this banner to a node',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'entityreference_entity_id',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_reference_node',
    'label' => 'Link',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 1,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_banner_collection-field_small_title'
  $field_instances['field_collection_item-field_banner_collection-field_small_title'] = array(
    'bundle' => 'field_banner_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add title for the banner',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_small_title',
    'label' => 'Title',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_banner_collection-field_teaser'
  $field_instances['field_collection_item-field_banner_collection-field_teaser'] = array(
    'bundle' => 'field_banner_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add description for the banner',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_teaser',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 300,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'fieldable_panels_pane-banner_pane-field_banner_collection'
  $field_instances['fieldable_panels_pane-banner_pane-field_banner_collection'] = array(
    'bundle' => 'banner_pane',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add banners content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_banner_collection',
    'label' => 'Banner',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'field_collection_embed',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add banners content.');
  t('Add description for the banner');
  t('Add title for the banner');
  t('Banner');
  t('Description');
  t('Icon');
  t('Link');
  t('Link this banner to a node');
  t('Select icon type for this banner');
  t('Title');

  return $field_instances;
}
