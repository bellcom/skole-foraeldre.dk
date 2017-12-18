<?php

/**
 * @file
 * The common settings.
 */

/**
 * Database Danish collation configuration example.
 */
$databases['default']['default']['collation'] = 'utf8_danish_ci';

/**
 * Cache configuration example.
 */
$conf['cache'] = 1;
$conf['page_compression'] = 1;
$conf['preprocess_css'] = 1;
$conf['preprocess_js'] = 1;

/**
 * Syslog configuration example.
 */
$conf['syslog_identity'] = $databases["default"]["default"]["database"];

/**
 * Prevent notifications configuration example.
 */
$conf['update_notify_emails'] = array();

/**
 * Add the domain module setup routine.
 */
include DRUPAL_ROOT . '/sites/all/modules/contrib/domain/settings.inc';

// Handle SSL termination.
if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
  $_SERVER['HTTPS'] = 'on';
}
