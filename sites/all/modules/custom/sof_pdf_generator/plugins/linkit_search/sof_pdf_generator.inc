<?php

/**
 * @file
 * Linkit views plugin.
 */

$plugin = array(
  'ui_title' => t('SOF pdf download links'),
  'ui_description' => t('Extend Linkit publication download links.'),
  'entity_type' => 'node',
  'handler' => array(
    'class' => 'LinkitPluginPdfDownload',
    'file' => 'linkit_plugin_pdf_download.class.php',
  ),
);
