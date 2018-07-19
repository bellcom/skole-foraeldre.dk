<?php
/**
 * @file
 * sof_magazine_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_magazine_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'magazine_pane';
  $fieldable_panels_pane_type->title = 'Magazine deck';
  $fieldable_panels_pane_type->description = 'Add magazine promotion as a deck';
  $export['magazine_pane'] = $fieldable_panels_pane_type;

  return $export;
}
