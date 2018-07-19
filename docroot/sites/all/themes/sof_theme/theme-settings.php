<?php

/**
 * @file
 * File for adding custom theme settings
 * theme-settings.php
 */

 /**
  * Preprocess theme settings form.
  */
function sof_theme_form_system_theme_settings_alter(&$form, &$form_state) {
  global $base_path;
  $theme = "sof_theme";
  // Footer logo Image.
  $default_footerlogo_image = $base_path . drupal_get_path('theme', $theme) . '/footer_logo.png';
  // Theme Settings.
  $footerlogo_image = theme_get_setting('footerlogo_image', $theme);
  $form['theme_images']['footerlogo'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer Logo image settings'),
    '#description' => t('If toggled on, the following logo will be displayed.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['theme_images']['footerlogo']['default_footer_logo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the default logo'),
    '#default_value' => theme_get_setting('default_footer_logo'),
    '#tree' => FALSE,
    '#description' => t('Check here if you want the theme to use the logo supplied with it.'),
  );
  $form['theme_images']['footerlogo']['settings'] = array(
    '#type' => 'container',
    '#states' => array(
      // Hide the logo settings when using the default logo.
      'invisible' => array(
        'input[name="default_footer_logo"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['theme_images']['footerlogo']['settings']['footerlogo_image'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to footer logo image'),
    '#default_value' => file_uri_scheme($footerlogo_image) == 'public' ? file_uri_target($footerlogo_image) : $footerlogo_image,
    '#field_suffix' => '<input type="button" class="form-submit" value="Upload Image" />',
    '#prefix' => '<img class="form-item image_preview" src="' . (!empty($footerlogo_image) ? file_create_url($footerlogo_image) : file_create_url($default_footerlogo_image)) . '" height="50" />',
    '#description' => t('The path to the file you would like to use as your footer logo image.'),
  );
  $form['theme_images']['footerlogo']['settings']['footerlogo_image_upload'] = array(
    '#type' => 'file',
    '#title' => t('Upload footer logo image'),
    '#size' => 40,
    '#description' => t("If you don't have direct file access to the server, use this field to upload your image."),
  );
  // Attach custom submit handler to the form.
  $form['#submit'][] = 'sof_theme_settings_submit';
}
 /**
  * Preprocess theme settings submit form.
  */
function sof_theme_settings_submit($form, &$form_state) {
  global $base_url;
  $theme = "sof_theme";
  // Header Image.
  $file = file_save_upload('footerlogo_image_upload');
  if ($file) {
    $parts = pathinfo($file->filename);
    $destination = 'public://' . $parts['basename'];
    $file->status = FILE_STATUS_PERMANENT;
    if (file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
      $_POST['footerlogo_image'] = $form_state['values']['footerlogo_image'] = $destination;
      unset($_POST['footerlogo_image_upload']);
      unset($form_state['values']['footerlogo_image_upload']);
      $form_state['values']['default_logo'] = 0;
    }
  }
  else {
    $_POST['footerlogo_image'] = $form_state['values']['footerlogo_image'] = $base_url . '/' . drupal_get_path('theme', $theme) . '/footer_logo.png';
  }
  if (!empty($form_state['values']['footerlogo_image']) && !file_uri_scheme($form_state['values']['footerlogo_image'])) {
    $_POST['footerlogo_image'] = $form_state['values']['footerlogo_image'] = 'public://' . $form_state['values']['footerlogo_image'];
  }
}
