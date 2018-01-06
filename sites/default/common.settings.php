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
 * Salt for one-time login links and cancel links, form tokens, etc.
 *
 * This variable will be set to a random value by the installer. All one-time
 * login links will be invalidated if the value is changed. Note that if your
 * site is deployed on a cluster of web servers, you must ensure that this
 * variable has the same value on each server. If this variable is empty, a hash
 * of the serialized database credentials will be used as a fallback salt.
 *
 * For enhanced security, you may set this variable to a value using the
 * contents of a file outside your docroot that is never saved together
 * with any backups of your Drupal files and database.
 *
 * Example:
 *   $drupal_hash_salt = file_get_contents('/home/example/salt.txt');
 *
 */
$drupal_hash_salt = '8t5k4MMGQOE9D3G89cMNUaQ-gj_ixqvldzsPNwakcN8';

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
