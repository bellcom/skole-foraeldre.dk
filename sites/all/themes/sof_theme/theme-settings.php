<?php
// @file: theme-settings.php
function sof_theme_form_system_theme_settings_alter(&$form, &$form_state) {
  // Container fieldset
  $form['footerlogo'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer Logo'),
  );
  
  // Default path for image
  $slogo_path = theme_get_setting('slogo_path');
  if (file_uri_scheme($slogo_path) == 'public') {
    $slogo_path = file_uri_target($slogo_path);
  }
  
  // Helpful text showing the file name, disabled to avoid the user thinking it can be used for any purpose.
  $form['footerlogo']['slogo_path'] = array(
    '#type' => 'textfield',
    '#title' => 'Path to footer logo image',
    '#default_value' => $slogo_path,
    '#disabled' => TRUE,
  );

  // Upload field
  $form['footerlogo']['slogo_upload'] = array(
    '#type' => 'file',
    '#title' => 'Upload footer logo image',
    '#description' => 'Upload a new image which be used as logo in footer.',
  );

  // Attach custom submit handler to the form
  $form['#submit'][] = 'sof_theme_settings_submit';
}

function sof_theme_settings_submit($form, &$form_state) {
  $settings = array();
  // Get the previous value
  $previous = 'public://' . $form['footerlogo']['slogo_path']['#default_value'];
  
  $file = file_save_upload('slogo_upload');
  if ($file) {
    $parts = pathinfo($file->filename);
    $destination = 'public://' . $parts['basename'];
    $file->status = FILE_STATUS_PERMANENT;
    
    if(file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
      $_POST['slogo_path'] = $form_state['values']['slogo_path'] = $destination;
      // If new file has a different name than the old one, delete the old
      if ($destination != $previous) {
        drupal_unlink($previous);
      }
    }
  } else {
    // Avoid error when the form is submitted without specifying a new image
    $_POST['slogo_path'] = $form_state['values']['slogo_path'] = $previous;
  }
  
}
