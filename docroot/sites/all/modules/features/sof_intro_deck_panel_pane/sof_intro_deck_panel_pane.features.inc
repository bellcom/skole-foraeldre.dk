<?php
/**
 * @file
 * sof_intro_deck_panel_pane.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_intro_deck_panel_pane_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "fieldable_panels_panes" && $api == "fieldable_panels_pane_type") {
    return array("version" => "1");
  }
}
