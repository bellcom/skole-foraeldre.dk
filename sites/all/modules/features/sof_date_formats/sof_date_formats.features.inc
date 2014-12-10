<?php
/**
 * @file
 * sof_date_formats.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_date_formats_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function sof_date_formats_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['d F Y'] = 'd F Y';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function sof_date_formats_date_format_types() {
  $format_types = array();
  // Exported date format type: sof_custom
  $format_types['sof_custom'] = 'SOF custom';
  return $format_types;
}
