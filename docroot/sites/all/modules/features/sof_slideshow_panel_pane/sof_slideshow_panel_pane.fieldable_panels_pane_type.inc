<?php
/**
 * @file
 * sof_slideshow_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_slideshow_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'slideshow_pane';
  $fieldable_panels_pane_type->title = 'Slideshow';
  $fieldable_panels_pane_type->description = 'Reference slider node to be shown as deck';
  $export['slideshow_pane'] = $fieldable_panels_pane_type;

  return $export;
}
