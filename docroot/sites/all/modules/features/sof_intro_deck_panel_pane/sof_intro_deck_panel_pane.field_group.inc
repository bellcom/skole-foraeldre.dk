<?php
/**
 * @file
 * sof_intro_deck_panel_pane.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sof_intro_deck_panel_pane_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_first_link_group|fieldable_panels_pane|intro_deck_pane|default';
  $field_group->group_name = 'group_first_link_group';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'intro_deck_pane';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'First links group',
    'weight' => '2',
    'children' => array(
      0 => 'field_five_links_first',
      1 => 'field_link_group_title_first',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'First links group',
      'instance_settings' => array(
        'classes' => ' group-first-link-group field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'fieldable_panels_pane_intro_deck_pane_full_group_first_link_group',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_first_link_group|fieldable_panels_pane|intro_deck_pane|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_first_link_group|fieldable_panels_pane|intro_deck_pane|form';
  $field_group->group_name = 'group_first_link_group';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'intro_deck_pane';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'First links group',
    'weight' => '3',
    'children' => array(
      0 => 'field_link_group_title_first',
      1 => 'field_five_links_first',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'First links group',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-first-link-group field-group-fieldset',
        'description' => '',
        'id' => 'fieldable_panels_pane_intro_deck_pane_form_group_first_link_group',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_first_link_group|fieldable_panels_pane|intro_deck_pane|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_second_links_group|fieldable_panels_pane|intro_deck_pane|default';
  $field_group->group_name = 'group_second_links_group';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'intro_deck_pane';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Second links group',
    'weight' => '3',
    'children' => array(
      0 => 'field_five_links_second',
      1 => 'field_link_group_title_second',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Second links group',
      'instance_settings' => array(
        'classes' => ' group-second-links-group field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'fieldable_panels_pane_intro_deck_pane_full_group_second_links_group',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_second_links_group|fieldable_panels_pane|intro_deck_pane|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_second_links_group|fieldable_panels_pane|intro_deck_pane|form';
  $field_group->group_name = 'group_second_links_group';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'intro_deck_pane';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Second links group',
    'weight' => '4',
    'children' => array(
      0 => 'field_link_group_title_second',
      1 => 'field_five_links_second',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-second-links-group field-group-fieldset',
        'required_fields' => 1,
        'id' => 'fieldable_panels_pane_intro_deck_pane_form_group_second_links_group',
      ),
    ),
  );
  $field_groups['group_second_links_group|fieldable_panels_pane|intro_deck_pane|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('First links group');
  t('Second links group');

  return $field_groups;
}
