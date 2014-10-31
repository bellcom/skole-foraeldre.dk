<?php

$plugin = array(
  'title'            => t('SOF toolbox search'),
  'single'           => TRUE,
  'category'         => array(t('SOF toolbox search'), 0),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form'        => 'sof_toolbox_search_content_type_edit_form',
  'render callback'  => 'sof_toolbox_search_content_type_render'
);


/**
 *	Edit form callback function
 */
 function sof_toolbox_search_content_type_edit_form($form, &$form_state){
  
  $conf = $form_state['conf'];
  
  $form['terms_wrapper'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Predefined toolbox terms'),
    '#weight'      => 5,
    '#collapsible' => FALSE,
    '#description' => t('Specify predefined search terms'),
  );
  
  
  //Add max 10 terms for bottom predefined search
  $delta = 0;
  for($delta =0;$delta <= 10; $delta++){
    $form['terms_wrapper']['term'][$delta] = array(
        '#title' => t('Term'),
        '#type' => 'textfield',
        '#default_value' => $conf['term_val'][$delta] ? $conf['term_val'][$delta] : '',
    ); 
  }
  
  return $form;
 }

 
 /**
  * Submit handler for edit form.
  */
 function sof_toolbox_search_content_type_edit_form_submit($form, &$form_state) {
     
   $form_state['conf']['term_val'] = $form_state['values'];
 
 }
 
/**
 * Run-time rendering of the body of the block (content type)
 * 
 * @todo construct the url for the search page on line 71 and 103
 */
function sof_toolbox_search_content_type_render($subtype, $conf, $args, $context) {
	$block = new stdClass();
	
    $items = array();
    
    //Deck upper part(search field)
    $items['toolbox_upper'] = array(
      '#type'       => 'container',
      '#attributes' => array(
        'id' => 'sof_toolboxdeck_top',
      ),
    );
    $items['toolbox_upper']['form'] = array(
      '#type'   => 'form',
      '#action' => '/'
    );
    $items['toolbox_upper']['form']['search'] = array(
        '#title' => t('Search area'),
        '#type'  => 'textfield',
        '#attributes' => array(
            'placeholder' => t('Search in all items in the toolbox'),
        ),
    ); 
    
    //Deck bottom part (links)
    //Get only numeric array keys with the terms
    $numerickeys = array_filter(array_keys($conf['term_val']), 'is_int');

    if(!empty($numerickeys)){
        
      $items['toolbox_bottom'] = array(
        '#type' => 'container',
        '#attributes' => array(
            'id' => 'sof_toolboxdeck_bottom',
        ),
      );
      
      foreach ($numerickeys as $key) {
        $items['toolbox_bottom']['predefinded_term'][$key] = array(
            '#type'    => 'link',
            '#title'   => $conf['term_val'][$key],
            '#options' => array(
                'attributes' => array(
                    'title'  => $conf['term_val'][$key],
                )
            ),
           '#href'    => '/',
        );
          
      }
        
    }    
    
    $block->content = theme('sof_toolbox_search',array( 'items' => $items ));
    
	return $block;
}

