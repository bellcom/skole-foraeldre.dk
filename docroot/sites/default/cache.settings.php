<?php

/**
 * @file
 * Cache backend.
 */

/**
// Memcached configuration examples.
 $conf['cache_backends'][] = 'sites/all/modules/contrib/memcache/memcache.inc';
 $conf['cache_default_class'] = 'MemCacheDrupal';
 $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
 $conf['memcache_key_prefix'] = 'skole';
 $conf['memcache_servers'] = array(
 '127.0.0.1:11211' => 'default',
 );
*/

// Varnish configuration examples.
$conf['cache_backends'][] = 'sites/all/modules/contrib/varnish/varnish.cache.inc';
$conf['cache_class_cache_page'] = 'VarnishCache';
$conf['varnish_control_key'] = '20c8cc49-944c-49f9-99fd-ed0f5e5c02d3';
$conf['reverse_proxy'] = TRUE;
$conf['reverse_proxy_addresses'] = array('127.0.0.1');
$conf['varnish_control_terminal'] = '127.0.0.1:6082';
$conf['varnish_version'] = 3;

// Add Varnish as the page cache handler.
