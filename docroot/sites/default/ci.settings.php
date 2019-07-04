<?php

/**
 * @file
 * The CI settings.php
 */

// Database config.
$databases = array (
  'default' => array (
    'default' => array (
      'database' => '__DB_NAME__',
      'username' => 'drupal',
      'password' => 'drupal',
      'host' => 't-4995b7752f288434.elb.eu-west-1.amazonaws.com',
      'port' => '3306',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

require('cache.settings.php');

// Cache override.
$conf["memcache_servers"] = array(
  "memcached:11211" => "default",
);

// Disable core search index.
$conf["search_cron_limit"] = "0";

// Overrides solr url variable used to set solr endpoint.
$conf["apachesolr_environment"]["solr"]["url"] = "http://solr:8983/solr/core1";

$conf["varnish_version"] = 4;
$conf["varnish_control_terminal"] = "varnish:6082";
$conf["varnish_control_key"] = "secret";

// Common settings for all installations.
require("common.settings.php");

// Change mail system with the test one to prevent sending not wanted emails.
$conf["mail_system"] = array(
  "default-system" => "TestingMailSystem",
  "webform" => "TestingMailSystem",
);

// Cache configuration.
$conf["cache"] = 0;
$conf["page_compression"] = 0;
$conf["preprocess_css"] = 0;
$conf["preprocess_js"] = 0;


$_SERVER["HTTPS"] = "on";
if (isset($_SERVER["HTTPS"]) && strtolower($_SERVER["HTTPS"]) == "on" && isset($base_url)) {
  $base_url = str_replace("http://", "https://", $base_url);
}


// Stage File Proxy config - to get images from prod.
$conf["stage_file_proxy_origin"] = "http://skole-foraeldre.dk";

$conf["file_temporary_path"] = "/tmp";

