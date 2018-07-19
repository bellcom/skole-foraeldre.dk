<?php
/**
 * @file
 * sof_banners_deck_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_banners_deck_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'banner_pane';
  $fieldable_panels_pane_type->title = 'Banners deck';
  $fieldable_panels_pane_type->description = 'Provides 3 banner boxes with content added by editor.';
  $export['banner_pane'] = $fieldable_panels_pane_type;

  return $export;
}
