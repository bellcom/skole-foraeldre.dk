<?php
/**
 * @file
 * sof_apache_solr_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_apache_solr_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
