<?php
/**
 * @file
 * sof_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function sof_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Contact block on the right side of the footer';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_contact_block';
  $fe_block_boxes->body = '<p>33 26 17 21<br />
post@skole-foraeldre.dk<br />
Skole og Forældre,<br />
Kvægtorvsgade 1, kld.<br />
1710 København V</p>
';

  $export['footer_contact_block'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Descripton block on the left side of the footer';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_desc_block';
  $fe_block_boxes->body = '<p>Skole og Forældre er landsorganisation for skolebestyrelser og forældre til børn i folkeskolen. Vi gør forældre og skolebestyrelsesmedlemmer stærkere.</p>
';

  $export['footer_desc_block'] = $fe_block_boxes;

  return $export;
}
