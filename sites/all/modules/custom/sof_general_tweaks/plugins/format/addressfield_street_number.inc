<?php

/**
 * @file
 * Extends the addressfield container with a street number field.
 */

/**
 * Define plugin.
 */
$plugin = array(
  'title' => t('Address street number'),
  'format callback' => 'addressfield_street_number_format',
  'type' => 'street_number',
  'weight' => 10,
);

/**
 * Implemens addressfield plugin callback.
 */
function addressfield_street_number_format(&$format, $address) {
  $format['street_block']['thoroughfare_street_number'] = array(
    '#title' => t('Street Number'),
    '#type' => 'textfield',
    '#size' => 5,
    '#attributes' => array(
      'class' => array('thoroughfare-street-number'),
    ),
    '#default_value' => isset($address['thoroughfare_street_number']) ? $address['thoroughfare_street_number'] : '',
    '#element_validate' => array('addressfield_street_number_validate'),
  );

  $format['street_block']['premise_street_number'] = array(
    '#title' => t('Street Number'),
    '#type' => 'textfield',
    '#size' => 5,
    '#attributes' => array(
      'class' => array('premise-street-number'),
    ),
    '#default_value' => isset($address['premise_street_number']) ? $address['premise_street_number'] : '',
    '#element_validate' => array('addressfield_street_number_validate'),
  );
}

/**
 * Implements street number field validation callback.
 *
 * Limit the field to maximum 4 digits.
 */
function addressfield_street_number_validate($element, &$form_state) {
  $value = $element['#value'];
  if ($value && (!is_numeric($value) || drupal_strlen($value) > 4)) {
    form_error($element, t('Invalid Street number.'));
  }
}
