<?php

/**
 * @file
 * The PRODUCTION settings.php
 */

// Database config.
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'sof',
      'username' => 'sof',
      'password' => 'fLA3DXMA',
      'host' => '127.0.0.1',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

// Common settings for all installations.
require('cache.settings.php');
require('common.settings.php');
