<?php
/**
 * @file
 * sof_full_html_deck_panel_pane.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_full_html_deck_panel_pane_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "fieldable_panels_panes" && $api == "fieldable_panels_pane_type") {
    return array("version" => "1");
  }
}
