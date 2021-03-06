<?php
/**
 * @file
 * sof_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sof_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['current_search-search_results'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'search_results',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven_subtheme',
        'weight' => -18,
      ),
      'sof_theme' => array(
        'region' => 'global_search_top_region',
        'status' => 1,
        'theme' => 'sof_theme',
        'weight' => -18,
      ),
    ),
    'title' => 'Search result',
    'visibility' => 0,
  );

  $export['follow-site'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'site',
    'module' => 'follow',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven_subtheme',
        'weight' => -22,
      ),
      'sof_theme' => array(
        'region' => 'top_header_navigation',
        'status' => 1,
        'theme' => 'sof_theme',
        'weight' => -22,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-top-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-top-navigation',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven_subtheme',
        'weight' => -23,
      ),
      'sof_theme' => array(
        'region' => 'top_header_navigation',
        'status' => 1,
        'theme' => 'sof_theme',
        'weight' => -23,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['sof_footer_social_media-sof_footer_social_media'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'sof_footer_social_media',
    'module' => 'sof_footer_social_media',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven_subtheme',
        'weight' => 0,
      ),
      'sof_theme' => array(
        'region' => 'social_media_region',
        'status' => 1,
        'theme' => 'sof_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'seven_subtheme',
        'weight' => -11,
      ),
      'sof_theme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'sof_theme',
        'weight' => -11,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-sof_shopping_cart_block-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'sof_shopping_cart_block-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'seven_subtheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven_subtheme',
        'weight' => -22,
      ),
      'sof_theme' => array(
        'region' => 'top_header_navigation',
        'status' => 1,
        'theme' => 'sof_theme',
        'weight' => -22,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
