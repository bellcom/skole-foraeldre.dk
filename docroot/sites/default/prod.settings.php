<?php

/**
 * @file
 * The PRODUCTION settings.php
 */

// Database config.
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'skole_foraeldre_dk',
      'username' => 'skole_foraeldre',
      'password' => 'yubWoeg6Qv',
      'host' => 'localhost',
      'port' => '3306',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

// Common settings for all installations.
require('cache.settings.php');
require('common.settings.php');

// Overwrite key prefix for each domain.
$current_domain = domain_get_domain();
if ($current_domain) {
  $conf['memcache_key_prefix'] = 'skole_' . $current_domain['subdomain'];
}
