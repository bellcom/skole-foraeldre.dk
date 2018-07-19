<?php
/**
 * @file
 * sof_context_configurations.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sof_context_configurations_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'footer_mailchimp';
  $context->description = 'Adds the mailchimp block to the footer';
  $context->tag = 'global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mailchimp_signup-sof_mailchimp_form' => array(
          'module' => 'mailchimp_signup',
          'delta' => 'sof_mailchimp_form',
          'region' => 'social_media_region',
          'weight' => '-10',
        ),
        'sof_footer_social_media-sof_footer_social_media' => array(
          'module' => 'sof_footer_social_media',
          'delta' => 'sof_footer_social_media',
          'region' => 'social_media_region',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the mailchimp block to the footer');
  t('global');
  $export['footer_mailchimp'] = $context;

  return $export;
}
