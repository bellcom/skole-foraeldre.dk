<?php

/**
 * @file
 * Custom layout for SOF two column and bottom design.
 */

$plugin = array(
  'title' => t('Sof two column bottom'),
  'category' => t('SOF Custom'),
  'icon' => 'sof-two-column-bottom.png',
  'theme' => 'panels-sof-two-column-bottom',
  'css' => 'sof-two-column-bottom.css',
  'regions' => array(
    'left' => t('Left column'),
    'right' => t('Right column'),
    'bottom' => t('Bottom column'),
  ),
);
