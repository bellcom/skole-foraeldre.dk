<?php
/**
 * @file
 * sof_mailchimp_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sof_mailchimp_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['mailchimp_signup-sof_mailchimp_form'] = array(
    'cache' => 5,
    'custom' => 0,
    'delta' => 'sof_mailchimp_form',
    'module' => 'mailchimp_signup',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven_subtheme',
        'weight' => 0,
      ),
      'sof_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sof_theme',
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
