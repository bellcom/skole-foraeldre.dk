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
  $field_group->data = '';
  $export['group_terms_and_conditions|commerce_order|commerce_order|form'] = $field_group;

  return $export;
}
