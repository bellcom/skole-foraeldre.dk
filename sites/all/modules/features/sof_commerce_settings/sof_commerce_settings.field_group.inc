<?php
/**
 * @file
 * sof_commerce_settings.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sof_commerce_settings_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_terms_and_conditions|commerce_order|commerce_order|form';
  $field_group->group_name = 'group_terms_and_conditions';
  $field_group->entity_type = 'commerce_order';
  $field_group->bundle = 'commerce_order';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Terms and Conditions',
    'weight' => '6',
    'children' => array(
      0 => 'field_accept_terms_and_condition',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_terms_and_conditions|commerce_order|commerce_order|form'] = $field_group;

  return $export;
}
