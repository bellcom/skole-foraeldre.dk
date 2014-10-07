<?php

// Plugin definition
$plugin = array(
  'title' => t('SOF Custom'),
  'category' => t('SOF Custom'),
  'icon' => 'sofcustom.png',
  'theme' => 'panels-sofcustom',
  'css' => 'sofcustom.css',
  'regions' => array(
   'left' => t('Left column'),
    'right' => t('Right column'),
    'bottom' => t('Bottom column')
  ),
);
