<?php
/**
 * @file
 * sof_recommended_items_deck_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_recommended_items_deck_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'recommended_items_pane';
  $fieldable_panels_pane_type->title = 'Recommended items deck';
  $fieldable_panels_pane_type->description = 'This deck is dependant on \'General category\' vocabulary.There are three columns with links. First column will be editor filled and the rest will be automatically random picked from the same category.';
  $export['recommended_items_pane'] = $fieldable_panels_pane_type;

  return $export;
}
