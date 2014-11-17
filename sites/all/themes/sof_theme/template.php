<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 *
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "adaptivetheme_subtheme" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "adaptivetheme_subtheme".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function adaptivetheme_subtheme_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.

  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function adaptivetheme_subtheme_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_page(&$vars) {
}
function adaptivetheme_subtheme_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_node(&$vars) {
}
function adaptivetheme_subtheme_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_comment(&$vars) {
}
function adaptivetheme_subtheme_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_block(&$vars) {
}
function adaptivetheme_subtheme_process_block(&$vars) {
}
// */


 /**
 * Preprocess variables for the html template.
 */
 
 // Add body class when page is not found  or access id denided
 function sof_theme_preprocess_html(&$vars) {
	$status = drupal_get_http_header("status");
	if(($status == '404 Not Found') || ($status == '403 Forbidden')){
		$vars['classes_array'][] = 'page-404';
	}
 }
 
/**
 * Override or insert variables into the page template for HTML output.
 */
function sof_theme_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

/**
 * Override or insert variables into the page template.
 */
function sof_theme_process_page(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

  // Add theme hook suggestion for search page
  if (arg(0)=='search' && arg(1) && arg(2)) { 
    $vars['theme_hook_suggestions'][] = 'page__search';
  }
}
/**
 * Override related content field in article node. Block:Related Content Single Blocks
 */
function sof_theme_field__field_related_content__article($variables) {
	//kpr($variables);
  $output = '';
  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . '&nbsp;</div>';
  }
  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
  	//kpr($item['node']);
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';
  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
  return $output;
}

 
/**
 * Override field field_video
 */
function sof_theme_field__field_video($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }
  
  // Render the item.
  $output .= '<div id="video"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $output .= drupal_render($item);
  }
  $output .= '</div>';
  return $output;
}
/**
 * Override field
 */
function sof_theme_preprocess_field(&$vars) {

  global $base_path;
  $element = $vars['element'];
  if($element['#field_name']== 'field_we_recommend_reference'){
  	
  	$nid = array_shift(array_keys($element['#items']));
	$title = $element['#object']->field_we_recommend_reference['und'][$nid]['entity']->title;
	$linktonode =$element['#items'][$nid]['entity']->vid;
	$vars['nodecustomlink'] = l(t($title), '/node/' . $linktonode . '', array(
        'attributes' => array(
            'class' => array('node-title-werecommend'),
        ),
        'fragment' => '',
        'external' =>true,
    ));
  }
    /**
     * Magazine Deck fields preprocess: Field Category title
    */
    if($element['#field_name']== 'field_small_title' && $element['#bundle'] == 'field_magazine_category'){
	    $vars['items'][0]['#prefix'] = '<a class="mag-deck-default" href="http://www.skoleborn.dk/" target="_blank">';
	    $vars['items'][0]['#suffix'] = '</a>';
	}
	
	/**
	 * Magazine Deck fields preprocess: Field Image
	*/
	if ($element['#field_name'] == 'field_image' && $element['#bundle'] == 'magazine_pane') {
		$vars['items'][0]['#prefix'] = '<a class="mag-deck-default" href="http://www.skoleborn.dk/" target="_blank">';
		$vars['items'][0]['#suffix'] = '</a>';
	}
	
    /**
     * Block: Related Content Single Block
    */
	  if ($element['#field_type'] == 'image') {
	    // Reduce number of images in related content reference view mode to single image
	    if ($element['#view_mode'] == 'related_content_reference') {
	       $item = reset($vars['items']);
	       $vars['items'] = array($item);
	    }
	  }

   /** 
    * Banner deck settings
   */
    //Display banner icon as image
    if ($element['#field_name'] == 'field_icon' && $element['#entity_type'] == 'field_collection_item') {
        
       $machine_value = $element['#items'][0]['value'];
       $icon_link = $base_path . drupal_get_path('theme', 'sof_theme') .'/css/images/banner_deck_images/icon_' . $machine_value . '.svg';
          
       $vars['element'][0]['#markup'] = '<img class="banner-deck-icon" alt="' . $machine_value . '" src="' . $icon_link . '"  />';
       $vars['items'][0]['#markup'] = '<img class="banner-deck-icon" alt="' . $machine_value . '" src="' . $icon_link . '" />';   
    } 
}

/**
 * Preprocess function for fieldable-panels-pane.tpl.php
 */
function sof_theme_preprocess_fieldable_panels_pane(&$variables) {
  $fieldable_pane_type = $variables['elements']['#bundle']; 
  //Add title on every deck
  switch($fieldable_pane_type){
        case 'news_pane':
            $variables['panetitle'] = t('News deck');
            break;
	    case 'video_pane':
            $variables['panetitle'] = t('Video deck');
            break;
		case 'also_see_pane':
       		 $variables['panetitle'] = t('Also see');
        break;
        case 'magazine_pane':
       		 $variables['panetitle'] = t('Magazine');
			 $variables['title'] = '';
			 if(!empty($variables['elements']['#fieldable_panels_pane']->title)) {
			    $variables['title'] = $variables['elements']['#fieldable_panels_pane']->title;
			  } 
        break;
		case 'recommended_items_pane':
       		 $variables['panetitle'] = t('School board - overview');
        break;
        case 'what_we_write_about_pane':
       		 $variables['panetitle'] = t('School and parents write about');
        break;
		 default:
             $variables['panetitle'] = '';
    } 
}

/**
 * Override or insert variables into the node templates.
 */
function sof_theme_preprocess_node(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];
  
    //Add theme sugestions for publication
    if ( $node->type == 'publication' ){
    	$variables['theme_hook_suggestion'] = 'node__publication__full';
    }
	//Add theme sugestions for news and articles 
  	if ( $node->type == 'news' || $node->type == 'article' ) {
	  	if($view_mode == 'full'){
	   		$variables['theme_hook_suggestion'] = 'node__articlenews__full';
            
            //Add print button link
            $variables['print_button'] = l(t('Print'), 'javascript:window.print()', array(
                'attributes' => array(
                    'class' => array('print-btn'),
                ),
                'fragment' => '',
                'external' =>true,
            ));
            
	        //Pass slider block $delta as variable
	        switch($node->type){
	            case 'article':
	                $variables['slider_block_delta'] = 'related_articles_slider-block';
	                break;
	            case 'news':
	                $variables['slider_block_delta'] = 'related_articles_slider-block_1';
	                break;
	        }        
		}
		//Realted Articles Side Block display
		else if($view_mode == 'related_content_reference'){
			$variables['theme_hook_suggestion'] = 'node__article__related_content_reference';	
		}
		//News Deck top article display
		else if($view_mode == 'primary_selected_node'){		
			$variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
			$variables['theme_hook_suggestion'] = 'node__news__newsdeck';
		}
		//See also deck display
		else if($view_mode == 'teaser'){
	        $variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
			$variables['theme_hook_suggestion'] = 'node__seealso_deck';
	    }
        //Video Deck display
        else if($view_mode == 'video_reference_listing'){
	        $variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
			$variables['theme_hook_suggestion'] = 'node__video_reference';
	    }
		//Link to nodes display
        else if($view_mode == 'links_to_nodes'){
	        $variables['submitted'] = FALSE;
	    }
		
    }
	if ($node->type == 'publication') {
		//Realted Publication Side Block display
		if($view_mode == 'related_content_reference'){
			$variables['theme_hook_suggestion'] = 'node__article__related_content_reference';	
		}
	}
 }  
/**
 * Implements theme_menu_tree__menu_block().
 */
function sof_theme_menu_tree__menu_block(&$variables) {
  return '<ul class="first-level">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link().
 */
function sof_theme_menu_link(array $variables) {
  $element = $variables['element'];
  //kpr($element);
  $description = '';
  $sub_menu    = '';
  $depth       = '';
  //get menu depth
	  	
	  $depth = $element['#original_link']['depth'];
  	
	  //get menu description on level 1
	  if ($depth == 1) {
	  	
	  	 if($element['#localized_options']){
	  		$description = $element['#localized_options']['attributes']['title'] ;
		 }
		 
		 if ($element['#below']) {
		   // Wrap in container
		    unset($element['#below']['#theme_wrappers']);
			$sub_menu = '<div class="second-level-main-container">';
			$sub_menu .= '<span class="menu-description">'. $description .'</span>';
		    $sub_menu .= '<ul class="second-level">' . drupal_render($element['#below']) . '</ul>';
			$sub_menu .='</div>';
		  }
		 
	  }  
	  //Depth 2 submenu
	  if ($depth == 2) {
	  	
	  	  if ($element['#below']) {
		   // Wrap in container
		    unset($element['#below']['#theme_wrappers']);
			$sub_menu = '<div class="third-level-main-container">';
		    $sub_menu .= '<ul class="third-level">' . drupal_render($element['#below']) . '</ul>';
			$sub_menu .='</div>';
		  }	
	  }
  		 
    
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}


/**
* Implements hook_textarea
* Remove resizable part
*/
function sof_theme_textarea($variables) {
  $element = $variables['element'];
  $element['#attributes']['name'] = $element['#name'];
  $element['#attributes']['id'] = $element['#id'];
  $element['#attributes']['cols'] = $element['#cols'];
  $element['#attributes']['rows'] = $element['#rows'];
  _form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}
     

/**
 * Preprocess search page result
 * 
 * @see template_preprocess_search_result()
 */
function sof_theme_preprocess_search_result(&$variables) {
 
 unset($variables['info_split']['user']);
 
 //Add node teaser instead of snippet
 $nid = $variables['result']['node']->entity_id;
 $node = node_load($nid);
 
 if($node){
   $variables['teaser'] = isset($node->field_teaser[LANGUAGE_NONE][0]['value']) 
    ?  $node->field_teaser[LANGUAGE_NONE][0]['value'] :  $variables['snippet'];
 }else{
     $variables['teaser'] = $variables['snippet'] ;
 }
 
}