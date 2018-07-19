<?php

/**
 * @file
 * Custom layout for SOF two column and bottom design.
 */

 /**
  * Function for building the naked layout.
  *
  * Page layout functions are called during theme settings submit to process and
  * return CSS to be written to file. Sidebar width and unit values are set in
  * theme settings and passed to this function as parameters.
  */
function naked() {
  $page_layout['naked'] = array(
    'title' => t('Naked'),
    'category' => t('AT Subtheme Custom Page Layout'),
    'method' => 'naked',
    'type' => 'page_layout',
    'admin css' => 'naked.admin.css',
    'device_groups' => array(
      'bigscreen',
      'tablet_landscape',
      'tablet_portrait',
      'smalltouch_landscape',
    ),
  );

  return $page_layout;
}

/**
 * CSS Builder for the naked layout.
 *
 * Page layout functions are called during theme settings submit to process and
 * return CSS to be written to file. Sidebar width and unit values are set in
 * theme settings and passed to this function as parameters.
 *
 * In essense you just write CSS here using the parameters as placeholders for
 * inserting the values. You might do some logic with those values first
 * depending on the complexity and nature of your layout. Its worth taking some
 * time to review AT Cores Page layouts for examples.
 */
function naked_layout($sidebar_first, $sidebar_second, $sidebar_unit) {
  $styles = <<<EOF
/* Nothing to output, this style is naked! */
EOF;

  return $styles;
}
