<?php
/**
 * @file
 * sof_date_formats.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sof_date_formats_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_sof_custom';
  $strongarm->value = 'd F Y';
  $export['date_format_sof_custom'] = $strongarm;

  return $export;
}
