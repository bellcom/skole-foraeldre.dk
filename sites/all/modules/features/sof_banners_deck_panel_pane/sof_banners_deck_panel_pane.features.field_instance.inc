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

  // Exported field_instance: 'field_collection_item-field_banner_collection-field_banner_link'
  $field_instances['field_collection_item-field_banner_collection-field_banner_link'] = array(
    'bundle' => 'field_banner_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add link for this banner',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'link_plain',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_banner_link',
    'label' => 'Link',
    'required' => 1,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 1,
        'profile' => 'sof_banner_deck_links',
      ),
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'link_field',
      'weight' => 36,
    ),
  );

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
  t('Add link for this banner');
  t('Add title for the banner');
  t('Banner');
  t('Description');
  t('Icon');
  t('Link');
  t('Select icon type for this banner');
  t('Title');

  return $field_instances;
}
