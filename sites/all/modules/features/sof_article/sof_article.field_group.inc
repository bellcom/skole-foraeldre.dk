<?php
/**
 * @file
 * sof_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sof_article_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_references|node|article|form';
  $field_group->group_name = 'group_content_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content references',
    'weight' => '6',
    'children' => array(
      0 => 'field_related_article',
      1 => 'field_related_content',
      2 => 'field_banner',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Content references',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_content_references|node|article|form'] = $field_group;

  return $export;
}
