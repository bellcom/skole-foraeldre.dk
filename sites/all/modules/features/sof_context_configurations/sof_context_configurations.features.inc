<?php
/**
 * @file
 * sof_context_configurations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_context_configurations_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
