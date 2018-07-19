<?php
/**
 * @file
 * sof_full_html_deck_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_full_html_deck_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'html_embed_pane';
  $fieldable_panels_pane_type->title = 'HTML embed deck';
  $fieldable_panels_pane_type->description = 'A deck making it possible to insert Full HTML code into a page.';
  $export['html_embed_pane'] = $fieldable_panels_pane_type;

  return $export;
}
