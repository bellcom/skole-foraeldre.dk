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
    "title" : "Newsletter",
    "settings" : {
      "path" : "",
      "submit_button" : "Send",
      "confirmation_message" : "Thank you! Your submission has been received!",
      "destination" : "",
      "mergefields" : {
        "EMAIL" : {
          "name" : "Email Address",
          "req" : true,
          "field_type" : "email",
          "public" : true,
          "show" : true,
          "order" : "1",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "EMAIL",
          "id" : 0
        },
        "FNAME" : 0,
        "LNAME" : 0,
        "MMERGE3" : 0,
        "MMERGE4" : 0
      },
      "description" : "The newsletter is published 1-2 times a month. Sign up below. You can always sign out\\u00a0 it again.",
      "doublein" : 0,
      "send_welcome" : 0,
      "include_interest_groups" : 0
    }
  }');
  return $items;
}
