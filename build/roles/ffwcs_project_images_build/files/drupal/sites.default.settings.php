<?php

$databases = array (
    'default' =>
        array (
            'default' =>
                array (
                    'database' => 'drupal',
                    'username' => 'drupal',
                    'password' => 'drupal',
                    'host' => 'mysql',
                    'port' => '',
                    'driver' => 'mysql',
                    'prefix' => '',
                ),
        ),
);

$update_free_access = FALSE;
$drupal_hash_salt = 'LESdSYJehJN7OGeASr0dHunhPtbKJgfJCjClbRnXZ2w';
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);
$conf['404_fast_paths_exclude'] = '/\/(?:styles)|(?:system\/files)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

// Stage File Proxy config - to get images from prod.
$conf["stage_file_proxy_origin"] = "http://skole-foraeldre.dk";

// Change mail system with the test one to prevent sending not wanted emails.
$conf["mail_system"] = array(
    "default-system" => "TestingMailSystem",
    "webform" => "TestingMailSystem",
);

// Overrides solr url variable used to set solr endpoint.
$conf['apachesolr_environment']['solr']['url'] = 'http://solr:8983/solr/core1';

/**
 * Cache configuration example.
 */
$conf['cache'] = 0;
$conf['page_compression'] = 0;
$conf['preprocess_css'] = 0;
$conf['preprocess_js'] = 0;

/**
 * Add the domain module setup routine.
 */
include DRUPAL_ROOT . '/sites/all/modules/contrib/domain/settings.inc';
