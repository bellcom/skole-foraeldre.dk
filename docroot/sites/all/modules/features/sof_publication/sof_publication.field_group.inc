<?php
/**
 * @file
 * sof_publication.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sof_publication_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generate_from_content|node|publication|form';
  $field_group->group_name = 'group_generate_from_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Generate from content',
    'weight' => '8',
    'children' => array(
      0 => 'field_pdf_content',
      1 => 'field_pdf_cover_color',
      2 => 'field_pdf_title',
      3 => 'field_pdf_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-generate-from-content field-group-fieldset',
        'required_fields' => 1,
        'id' => 'node_publication_form_group_generate_from_content',
      ),
    ),
  );
  $field_groups['group_generate_from_content|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_upload|node|publication|form';
  $field_group->group_name = 'group_upload';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Upload file',
    'weight' => '7',
    'children' => array(
      0 => 'field_file',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-upload field-group-fieldset',
        'required_fields' => 1,
        'id' => 'node_publication_form_group_upload',
      ),
    ),
  );
  $field_groups['group_upload|node|publication|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Generate from content');
  t('Upload file');

  return $field_groups;
}
