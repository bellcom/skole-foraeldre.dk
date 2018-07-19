<?php
/**
 * @file
 * sof_full_html_deck_panel_pane.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sof_full_html_deck_panel_pane_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'fieldable_panels_pane-html_embed_pane-field_full_html_field'.
  $field_instances['fieldable_panels_pane-html_embed_pane-field_full_html_field'] = array(
    'bundle' => 'html_embed_pane',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add your HTML markup to the deck',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
          'field_multiple_limit_order' => 0,
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_full_html_field',
    'label' => 'Full HTML field',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add your HTML markup to the deck');
  t('Full HTML field');

  return $field_instances;
}
