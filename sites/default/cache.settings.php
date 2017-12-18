<?php

/**
 * @file
 * Cache backend.
 */

// Memcached configuration examples.
include_once('./includes/cache.inc');
include_once('./sites/all/modules/contrib/memcache/memcache.inc');
$conf['cache_backends'][] = 'sites/all/modules/contrib/memcache/memcache.inc';
$conf['cache_default_class'] = 'MemCacheDrupal';
$conf['lock_inc'] = 'sites/all/modules/contrib/memcache/memcache-lock.inc';
$conf['memcache_stampede_protection'] = TRUE;
$conf['cache_default_class'] = 'MemCacheDrupal';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
$conf['memcache_servers'] = array(
  '127.0.0.1:11211' => 'default',
);
$conf['memcache_key_prefix'] = $databases["default"]["default"]["database"];

// Varnish configuration examples.
$conf['cache_backends'][] = 'sites/all/modules/contrib/varnish/varnish.cache.inc';
$conf['cache_class_cache_page'] = 'VarnishCache';
$conf['varnish_control_key'] = '1ace8d07-f515-4c12-bdfe-96ee0160a9c5';
$conf['reverse_proxy'] = TRUE;
$conf['reverse_proxy_addresses'] = array('127.0.0.1');
$conf['varnish_control_terminal'] = '127.0.0.1:6082';
$conf['varnish_version'] = 3;
