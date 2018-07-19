<?php
/**
 * @file
 * sof_also_see_deck_panel_pane.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sof_also_see_deck_panel_pane_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_fieldable_panels_pane__also_see_pane';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_fieldable_panels_pane__also_see_pane'] = $strongarm;

  return $export;
}
