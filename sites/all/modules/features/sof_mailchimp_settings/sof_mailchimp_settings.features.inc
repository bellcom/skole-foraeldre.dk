<?php
/**
 * @file
 * sof_mailchimp_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sof_mailchimp_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_mailchimp_signup().
 */
function sof_mailchimp_settings_default_mailchimp_signup() {
  $items = array();
  $items['sof_mailchimp_form'] = entity_import('mailchimp_signup', '{
    "name" : "sof_mailchimp_form",
    "mc_lists" : { "54dd9a130a" : "54dd9a130a" },
    "mode" : "1",
    "title" : "Nyhedsbrev",
    "settings" : {
      "path" : "",
      "submit_button" : "Send",
      "confirmation_message" : "Tak for din tilmelding til nyhedsbrevet.",
      "destination" : "",
      "mergefields" : { "EMAIL" : {"tag":"EMAIL","name":"Email Address","type":"email","required":true,"default_value":"","public":true,"display_order":"1","options":{"size":"25"}} },
      "description" : "Tilmeld dig Skole og For\\u00e6ldres nyhedsbrev.",
      "doublein" : 0,
      "send_welcome" : 0,
      "include_interest_groups" : 0
    }
  }');
  return $items;
}
