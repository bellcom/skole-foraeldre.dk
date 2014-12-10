<?php
/**
 * @file
 * sof_variables.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sof_variables_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_image_index_styles';
  $strongarm->value = array(
    'article_top_slider' => 'article_top_slider',
    'related_content_reference_image' => 'related_content_reference_image',
    'flexslider_full' => 0,
    'flexslider_thumbnail' => 0,
    'thumbnail' => 0,
    'medium' => 0,
    'large' => 0,
    'linkit_thumb' => 0,
    'media_thumbnail' => 0,
    'publication_related' => 0,
  );
  $export['apachesolr_image_index_styles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_seo';
  $strongarm->value = '1';
  $export['domain_seo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'node' => array(
      'primary_selected_node' => array(
        'label' => 'Primary selected node',
        'custom settings' => 1,
      ),
      'video_reference_listing' => array(
        'label' => 'Video reference listing',
        'custom settings' => 1,
      ),
      'links_to_nodes' => array(
        'label' => 'Links to nodes',
        'custom settings' => 1,
      ),
      'related_content_reference' => array(
        'label' => 'Related content reference',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_string_source_language';
  $strongarm->value = 'en';
  $export['i18n_string_source_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_admin_version';
  $strongarm->value = '';
  $export['jquery_update_jquery_admin_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.5';
  $export['jquery_update_jquery_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'home';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_register';
  $strongarm->value = '0';
  $export['user_register'] = $strongarm;

  return $export;
}
