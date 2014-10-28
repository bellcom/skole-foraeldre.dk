<?php
/**
 * @file
 * sof_also_see_deck_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_also_see_deck_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'also_see_pane';
  $fieldable_panels_pane_type->title = 'Also see deck';
  $fieldable_panels_pane_type->description = 'Provides a list of editor selected nodes of type article and news. Also one additional link to external pages.';
  $export['also_see_pane'] = $fieldable_panels_pane_type;

  return $export;
}
