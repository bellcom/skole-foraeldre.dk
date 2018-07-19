<?php
/**
 * @file
 * sof_intro_deck_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_intro_deck_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'intro_deck_pane';
  $fieldable_panels_pane_type->title = 'Intro deck';
  $fieldable_panels_pane_type->description = 'Adds description, link and 2 groups with 5 links as intro deck';
  $export['intro_deck_pane'] = $fieldable_panels_pane_type;

  return $export;
}
