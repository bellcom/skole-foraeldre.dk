<?php
/**
 * @file
 * sof_mailchimp_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sof_mailchimp_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailchimp_api_key';
  $strongarm->value = '97eacb6705fa2816b12c5fa75f18501d-us9';
  $export['mailchimp_api_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailchimp_batch_limit';
  $strongarm->value = '100';
  $export['mailchimp_batch_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailchimp_cron';
  $strongarm->value = 0;
  $export['mailchimp_cron'] = $strongarm;

  return $export;
}
