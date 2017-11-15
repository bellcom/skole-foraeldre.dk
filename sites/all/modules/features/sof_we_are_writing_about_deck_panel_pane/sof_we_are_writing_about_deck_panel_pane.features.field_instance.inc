<?php
/**
 * @file
 * sof_we_are_writing_about_deck_panel_pane.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sof_we_are_writing_about_deck_panel_pane_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'fieldable_panels_pane-what_we_write_about_pane-field_we_recommend_reference'.
  $field_instances['fieldable_panels_pane-what_we_write_about_pane-field_we_recommend_reference'] = array(
    'bundle' => 'what_we_write_about_pane',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select 5 recommended nodes',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
          'links' => 1,
          'view_mode' => 'links_to_nodes',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_we_recommend_reference',
    'label' => 'We recommend‎',
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
        'references_dialog_add' => 1,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 1,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Select 5 recommended nodes');
  t('We recommend‎');

  return $field_instances;
}
