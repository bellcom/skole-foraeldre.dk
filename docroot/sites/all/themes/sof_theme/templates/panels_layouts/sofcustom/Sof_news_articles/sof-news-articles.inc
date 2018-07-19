<?php

/**
 * @file
 * Custom layout for SOF News and Articles.
 */

$plugin = array(
  'title' => t('Sof news articles'),
  'category' => t('SOF Custom'),
  'icon' => 'sof-news-articles.png',
  'theme' => 'panels-sof-news-articles',
  'css' => 'sof-news-articles.css',
  'regions' => array(
    'left' => t('Left Region'),
    'right' => t('Right Region'),
    'bottom' => t('Bottom Region'),
  ),
);
