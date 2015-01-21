<?php

/**
 * @file
 * Ctools content type for rendering the toolbox search.
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

$plugin = array(
  'title' => t('SOF toolbox search'),
  'single' => TRUE,
  'category' => array(
    t('SOF toolbox search'),
    0,
  ),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'sof_toolbox_search_content_type_edit_form',
  'render callback' => 'sof_toolbox_search_content_type_render',
);

/**
 * Edit form callback function.
 */
function sof_toolbox_search_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  // Add max 10 terms for bottom predefined search.
  $form['terms_val'] = array(
    '#title' => t('Terms'),
    '#type' => 'textarea',
    '#default_value' => $conf['terms_val'] ? $conf['terms_val'] : '',
    '#description' => t('Use comma or new line to separate the terms'),
  );

  return $form;
}

/**
 * Submit handler for edit form.
 */
function sof_toolbox_search_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['terms_val'] = $form_state['values']['terms_val'];
}

/**
 * Run-time rendering of the body of the block (content type).
 */
function sof_toolbox_search_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $items = array();

  // Deck upper part(search field).
  $sof_tsf = drupal_get_form('sof_toolbox_search_form', $context);
  $items['toolbox_upper'] = array(
    '#type' => 'item',
    '#markup' => drupal_render($sof_tsf),
  );

  // Deck bottom part (links).
  // Get only numeric array keys with the terms.
  if (!empty($conf['terms_val'])) {
    $data = array_map('trim', preg_split("/[\r\n,]+/", $conf['terms_val'], -1, PREG_SPLIT_NO_EMPTY));

    foreach ($data as $key => $value) {
      $links[] = l($value, 'search/site/' . $value, array(
        'attributes' => array('title' => $value),
        'query' => array(
          'fq' => array(
            'bundle:(article OR news)',
            ((isset($context->data->field_category_single['und'][0]['tid'])) ? 'im_field_category:' . $context->data->field_category_single['und'][0]['tid'] : NULL),
          ),
        ),
      ));
    }

    $items['toolbox_bottom'] = array(
      '#title' => t('Other searches'),
      '#theme' => 'item_list',
      '#items' => $links,
      '#attributes' => array(
        'id' => 'sof_toolboxdeck_bottom',
        'class' => array('inline'),
      ),
    );
  }

  $block->content = theme('sof_toolbox_search', array('items' => $items));

  return $block;
}

/**
 * Implements hook_form().
 */
function sof_toolbox_search_form($form, &$form_state, $context) {
  // Seach field.
  $form['search_field'] = array(
    '#title' => t('Search area'),
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => t('Search in all items in the toolbox')),
  );

  // Context from the form.
  $form['store'] = array(
    '#type' => 'value',
    '#value' => $context,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#attributes' => array('class' => array('element-invisible')),
  );

  return $form;
}

/**
 * Submit hanlder for "sof_toolbox_search_form".
 */
function sof_toolbox_search_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['search_field'])) {
    // Node context in local variable.
    $context = $form_state['values']['store'];

    // Redirect to seach page with preset filters.
    $field = (isset($context->data->field_category_single['und'][0]['tid'])) ? 'im_field_category:' . $context->data->field_category_single['und'][0]['tid'] : NULL;
    drupal_goto('search/site/' . $form_state['values']['search_field'], array(
      'query' => array(
        'fq' => array(
          'bundle:(article OR news)',
          $field,
        ),
      ),
    ));
  }
}
