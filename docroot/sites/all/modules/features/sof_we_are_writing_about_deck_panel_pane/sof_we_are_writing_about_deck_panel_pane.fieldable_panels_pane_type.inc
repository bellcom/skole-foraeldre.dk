<?php
/**
 * @file
 * sof_we_are_writing_about_deck_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_we_are_writing_about_deck_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'what_we_write_about_pane';
  $fieldable_panels_pane_type->title = 'What we write about deck';
  $fieldable_panels_pane_type->description = 'A deck displaying content promoted by editors, most read and last updated.';
  $export['what_we_write_about_pane'] = $fieldable_panels_pane_type;

  return $export;
}
