<?php
/**
 * @file
 * sof_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sof_news_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bottomaregion|node|news|full';
  $field_group->group_name = 'group_bottomaregion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom Article Region',
    'weight' => '2',
    'children' => array(
      0 => 'field_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => ' group-bottomaregion field-group-div',
        'id' => 'node_news_full_group_bottomaregion',
      ),
    ),
  );
  $field_groups['group_bottomaregion|node|news|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_references|node|news|form';
  $field_group->group_name = 'group_content_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content references',
    'weight' => '6',
    'children' => array(
      0 => 'field_banner',
      1 => 'field_link',
      2 => 'field_related_content',
      3 => 'field_related_news',
      4 => 'field_set_rt_manually',
      5 => 'field_related_terms',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-content-references field-group-fieldset',
        'required_fields' => 1,
        'id' => 'node_news_form_group_content_references',
      ),
    ),
  );
  $field_groups['group_content_references|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_leftaregion|node|news|full';
  $field_group->group_name = 'group_leftaregion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Article Region',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_add_this',
      2 => 'field_image_slider',
      3 => 'field_teaser',
      4 => 'field_video',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left Article Region',
      'instance_settings' => array(
        'classes' => ' group-leftaregion field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_news_full_group_leftaregion',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_leftaregion|node|news|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_group|node|news|form';
  $field_group->group_name = 'group_media_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '5',
    'children' => array(
      0 => 'field_image_slider',
      1 => 'field_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-media-group field-group-fieldset',
        'required_fields' => 1,
        'id' => 'node_news_form_group_media_group',
      ),
    ),
  );
  $field_groups['group_media_group|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rightaregion|node|news|full';
  $field_group->group_name = 'group_rightaregion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Article Region',
    'weight' => '1',
    'children' => array(
      0 => 'field_banner',
      1 => 'field_related_content',
      2 => 'field_related_terms',
      3 => 'download_as_pdf',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => ' group-rightaregion field-group-div',
        'id' => 'node_news_full_group_rightaregion',
      ),
    ),
  );
  $field_groups['group_rightaregion|node|news|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Bottom Article Region');
  t('Content references');
  t('Left Article Region');
  t('Media');
  t('Right Article Region');

  return $field_groups;
}
