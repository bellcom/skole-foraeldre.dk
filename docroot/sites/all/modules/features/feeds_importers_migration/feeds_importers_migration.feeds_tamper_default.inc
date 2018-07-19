<?php
/**
 * @file
 * feeds_importers_migration.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function feeds_importers_migration_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'articles_importer-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'articles_importer';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['articles_importer-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'articles_importer-xpathparser_0-trim';
  $feeds_tamper->importer = 'articles_importer';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}-',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['articles_importer-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'articles_importer-xpathparser_1-required';
  $feeds_tamper->importer = 'articles_importer';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['articles_importer-xpathparser_1-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'articles_importer-xpathparser_3-required';
  $feeds_tamper->importer = 'articles_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Required field';
  $export['articles_importer-xpathparser_3-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'articles_importer-xpathparser_3-strtotime';
  $feeds_tamper->importer = 'articles_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = '';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['articles_importer-xpathparser_3-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'articles_importer-xpathparser_4-convert_case';
  $feeds_tamper->importer = 'articles_importer';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['articles_importer-xpathparser_4-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'articles_importer-xpathparser_4-trim';
  $feeds_tamper->importer = 'articles_importer';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{-}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['articles_importer-xpathparser_4-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'files-xpathparser_0-trim';
  $feeds_tamper->importer = 'files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'files-xpathparser_1-trim';
  $feeds_tamper->importer = 'files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'files-xpathparser_2-trim';
  $feeds_tamper->importer = 'files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'files-xpathparser_3-trim';
  $feeds_tamper->importer = 'files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'fr_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'fr_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'fr_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'fr_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'fr_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'fr_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'fr_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'fr_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'fr_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'fr_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'fr_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'fr_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'fr_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'fr_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'fr_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'fr_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_images-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'fr_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files_images-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_images-xpathparser_0-trim';
  $feeds_tamper->importer = 'fr_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files_images-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_images-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'fr_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files_images-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_images-xpathparser_1-trim';
  $feeds_tamper->importer = 'fr_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files_images-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_images-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'fr_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files_images-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_images-xpathparser_2-trim';
  $feeds_tamper->importer = 'fr_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files_images-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_images-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'fr_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['fr_files_images-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'fr_files_images-xpathparser_3-trim';
  $feeds_tamper->importer = 'fr_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['fr_files_images-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'gidis_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'gidis_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'gidis_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'gidis_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'gidis_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'gidis_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'gidis_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'gidis_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'gidis_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'gidis_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'gidis_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'gidis_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'gidis_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'gidis_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'gidis_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'gidis_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_images-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'gidis_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files_images-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_images-xpathparser_0-trim';
  $feeds_tamper->importer = 'gidis_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files_images-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_images-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'gidis_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files_images-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_images-xpathparser_1-trim';
  $feeds_tamper->importer = 'gidis_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files_images-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_images-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'gidis_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files_images-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_images-xpathparser_2-trim';
  $feeds_tamper->importer = 'gidis_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files_images-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_images-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'gidis_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['gidis_files_images-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gidis_files_images-xpathparser_3-trim';
  $feeds_tamper->importer = 'gidis_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['gidis_files_images-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'inkl_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'inkl_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'inkl_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'inkl_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'inkl_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'inkl_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'inkl_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'inkl_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'inkl_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'inkl_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'inkl_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'inkl_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'inkl_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'inkl_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'inkl_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'inkl_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'inkl_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_images-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images-xpathparser_0-trim';
  $feeds_tamper->importer = 'inkl_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_images-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'inkl_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_images-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images-xpathparser_1-trim';
  $feeds_tamper->importer = 'inkl_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_images-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'inkl_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_images-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images-xpathparser_2-trim';
  $feeds_tamper->importer = 'inkl_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_images-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'inkl_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_images-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images-xpathparser_3-trim';
  $feeds_tamper->importer = 'inkl_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_images-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images_folder-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'inkl_files_images_folder';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_images_folder-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images_folder-xpathparser_0-trim';
  $feeds_tamper->importer = 'inkl_files_images_folder';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_images_folder-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images_folder-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'inkl_files_images_folder';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_images_folder-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images_folder-xpathparser_1-trim';
  $feeds_tamper->importer = 'inkl_files_images_folder';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_images_folder-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images_folder-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'inkl_files_images_folder';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_images_folder-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images_folder-xpathparser_2-trim';
  $feeds_tamper->importer = 'inkl_files_images_folder';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_images_folder-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images_folder-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'inkl_files_images_folder';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['inkl_files_images_folder-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inkl_files_images_folder-xpathparser_3-trim';
  $feeds_tamper->importer = 'inkl_files_images_folder';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['inkl_files_images_folder-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'news_importer-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'news_importer';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['news_importer-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'news_importer-xpathparser_0-trim';
  $feeds_tamper->importer = 'news_importer';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}-',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['news_importer-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'news_importer-xpathparser_1-required';
  $feeds_tamper->importer = 'news_importer';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['news_importer-xpathparser_1-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'news_importer-xpathparser_3-required';
  $feeds_tamper->importer = 'news_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['news_importer-xpathparser_3-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'news_importer-xpathparser_4-convert_case';
  $feeds_tamper->importer = 'news_importer';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['news_importer-xpathparser_4-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'news_importer-xpathparser_4-trim';
  $feeds_tamper->importer = 'news_importer';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}-',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['news_importer-xpathparser_4-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'noko_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'noko_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'noko_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'noko_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'noko_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'noko_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'noko_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'noko_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'noko_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'noko_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'noko_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'noko_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'noko_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'noko_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'noko_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'noko_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_images-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'noko_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files_images-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_images-xpathparser_0-trim';
  $feeds_tamper->importer = 'noko_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files_images-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_images-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'noko_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files_images-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_images-xpathparser_1-trim';
  $feeds_tamper->importer = 'noko_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files_images-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_images-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'noko_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files_images-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_images-xpathparser_2-trim';
  $feeds_tamper->importer = 'noko_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files_images-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_images-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'noko_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['noko_files_images-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'noko_files_images-xpathparser_3-trim';
  $feeds_tamper->importer = 'noko_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['noko_files_images-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'sof_files_';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_-xpathparser_0-trim';
  $feeds_tamper->importer = 'sof_files_';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'sof_files_';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_-xpathparser_1-trim';
  $feeds_tamper->importer = 'sof_files_';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'sof_files_';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_-xpathparser_2-trim';
  $feeds_tamper->importer = 'sof_files_';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'sof_files_';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_-xpathparser_3-trim';
  $feeds_tamper->importer = 'sof_files_';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'sof_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'sof_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'sof_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'sof_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'sof_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'sof_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'sof_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'sof_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_images-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'sof_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_images-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_images-xpathparser_0-trim';
  $feeds_tamper->importer = 'sof_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_images-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_images-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'sof_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_images-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_images-xpathparser_1-trim';
  $feeds_tamper->importer = 'sof_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_images-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_images-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'sof_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_images-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_images-xpathparser_2-trim';
  $feeds_tamper->importer = 'sof_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_images-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_images-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'sof_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sof_files_images-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sof_files_images-xpathparser_3-trim';
  $feeds_tamper->importer = 'sof_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sof_files_images-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'sofkbh_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'sofkbh_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'sofkbh_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'sofkbh_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'sofkbh_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'sofkbh_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'sofkbh_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'sofkbh_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_files-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'sofkbh_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files_files-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_files-xpathparser_0-trim';
  $feeds_tamper->importer = 'sofkbh_files_files';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files_files-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_files-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'sofkbh_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files_files-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_files-xpathparser_1-trim';
  $feeds_tamper->importer = 'sofkbh_files_files';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files_files-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_files-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'sofkbh_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files_files-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_files-xpathparser_2-trim';
  $feeds_tamper->importer = 'sofkbh_files_files';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files_files-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_files-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'sofkbh_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files_files-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_files-xpathparser_3-trim';
  $feeds_tamper->importer = 'sofkbh_files_files';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files_files-xpathparser_3-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_images-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'sofkbh_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files_images-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_images-xpathparser_0-trim';
  $feeds_tamper->importer = 'sofkbh_files_images';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files_images-xpathparser_0-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_images-xpathparser_1-convert_case';
  $feeds_tamper->importer = 'sofkbh_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files_images-xpathparser_1-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_images-xpathparser_1-trim';
  $feeds_tamper->importer = 'sofkbh_files_images';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files_images-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_images-xpathparser_2-convert_case';
  $feeds_tamper->importer = 'sofkbh_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files_images-xpathparser_2-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_images-xpathparser_2-trim';
  $feeds_tamper->importer = 'sofkbh_files_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files_images-xpathparser_2-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_images-xpathparser_3-convert_case';
  $feeds_tamper->importer = 'sofkbh_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['sofkbh_files_images-xpathparser_3-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'sofkbh_files_images-xpathparser_3-trim';
  $feeds_tamper->importer = 'sofkbh_files_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '-{}',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['sofkbh_files_images-xpathparser_3-trim'] = $feeds_tamper;

  return $export;
}
