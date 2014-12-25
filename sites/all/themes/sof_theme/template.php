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
  global $base_path;
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
    $variables['theme_hook_suggestions'][] = 'page__search';
  }
  if($variables['theme_hook_suggestions'][0] == 'page__taxonomy'){
    $variables['theme_hook_suggestions'][] = 'page__search';
  }
  $variables['footer_logo'] = $base_path . drupal_get_path('theme', 'sof_theme') .'/css/images/footerlogo/footer_logo.png';
}

/**
 * Override related content field in article node. Block:Related Content Single Blocks
 */
function sof_theme_field__field_related_content__article($variables) {
  $output = '';
  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . '&nbsp;</div>';
  }
  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
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
    $nid = key($element['#items']);
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
    * Display banner icon as image
   */
  if($element['#field_name'] == 'field_icon' && $element['#entity_type'] == 'field_collection_item') {
    $machine_value = $element['#items'][0]['value'];
    $icon_link = $base_path . drupal_get_path('theme', 'sof_theme') .'/css/images/banner_deck_images/icon_' . $machine_value . '.svg';
    $vars['element'][0]['#markup'] = '<img class="banner-deck-icon" alt="' . $machine_value . '" src="' . $icon_link . '"  />';
    $vars['items'][0]['#markup'] = '<img class="banner-deck-icon" alt="' . $machine_value . '" src="' . $icon_link . '" />';
  }
}

/**
 * Preprocess function for apache solr search field - Add placeholder
 */
function sof_theme_form_alter(&$form, &$form_state, $form_id) {
  //Add placeholder to search page block
  $form['basic']['keys']['#attributes']['placeholder'] = t('Search');
  //Add placeholder to publuication listing page search block
  $form['apachesolr_panels_search_form']['#attributes']['placeholder'] = t('Search within publications');
  if($form['#id'] == 'commerce-cart-add-to-cart-form-1'){
    $amount         = $form_state['default_product']->commerce_price[LANGUAGE_NONE][0]['amount'];
    $currency_code  = $form_state['default_product']->commerce_price[LANGUAGE_NONE][0]['currency_code'];
    $price = commerce_currency_format($amount,$currency_code);
    $form['submit']['#value'] = t('Order Publications'). " " . "(" .$price .")";
  }
}

/**
 * Preprocess function for fieldable-panels-pane.tpl.php
 */
function sof_theme_preprocess_fieldable_panels_pane(&$variables) {

  $fieldable_pane_type = $variables['elements']['#bundle'];
  //Add title on every deck
  switch($fieldable_pane_type){
     case 'news_pane':{

      $variables['panetitle'] = $variables['elements']['#fieldable_panels_pane']->title;

      //Follow site block
      if ( $get_follow_site_block = block_load('follow', 'site')){
        $variables['followlinks'] = _block_get_renderable_array(_block_render_blocks(array($get_follow_site_block)));
      }

     }
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
  if ($node->type == 'publication'){
    $variables['theme_hook_suggestion'] = 'node__publication__full';
  }

  //Add theme sugestions for news and articles
  if($node->type == 'news' || $node->type == 'article') {
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
      //Publication link variable
      if($variables['field_publication_control_link'][LANGUAGE_NONE][0]['value'] == 1){
        $variables['publication_link'] = l(t('See all publications'), 'releases', array(
          'attributes' => array(
            'class' => array('publications-btn'),
           ),
           'fragment' => '',
        ));
      }
      //Related terms block
      if ($get_related_block = block_load('views', 'related_content-block')){
        $variables['blockrelatedterms'] = _block_get_renderable_array(_block_render_blocks(array($get_related_block)));
      }
      //Related articles/news slideshow
      if ($get_slider_block = block_load('views', $node->type == 'article' ? 'related_articles_slider-block' : 'related_articles_slider-block_1')){
        $variables['blockrelatedslider'] = _block_get_renderable_array(_block_render_blocks(array($get_slider_block)));
      }
      //Read Also Content
      if ($get_read_also_block = block_load('views', 'read_also-block')){
       $variables['blockrelatedcontent'] = _block_get_renderable_array(_block_render_blocks(array($get_read_also_block)));
      }
      //Alter submited by author
      $user = user_load($variables['uid']);
      $variables['submitted'] =  t('Submitted on !datetime by !username',
        array(
          '!datetime' => format_date($node->type == 'article' ? $variables['changed'] : $variables['created'], 'sof_custom'),
          '!username' => l($user->name, 'mailto:'.$user->mail , array('absolute' => TRUE)),
        ));
    }
    //Realted Articles Side Block display
    else if($view_mode == 'related_content_reference') {
      $variables['theme_hook_suggestion'] = 'node__article__related_content_reference';
    }
    //News Deck top article display
    else if($view_mode == 'primary_selected_node') {
      $variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
      $variables['theme_hook_suggestion'] = 'node__news__newsdeck';
    }
    //See also deck display
    else if($view_mode == 'teaser') {
      $variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
      $variables['theme_hook_suggestion'] = 'node__seealso_deck';
    }
    //Video Deck display
    else if($view_mode == 'video_reference_listing') {
      $variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
      $variables['theme_hook_suggestion'] = 'node__video_reference';
    }
    //Link to nodes display
    else if($view_mode == 'links_to_nodes'){
      $variables['submitted'] = FALSE;
    }
  }
  //Realted Publication Side Block display
  if ($node->type == 'publication') {
    if($view_mode == 'related_content_reference'){
      $variables['theme_hook_suggestion'] = 'node__article__related_content_reference';
    }
    //Add variable with related publications block
    if($view_mode == 'full'){
      if ( $get_publication_block = block_load('views', 'other_releases-block')){
        $variables['blockotherelease'] = _block_get_renderable_array(_block_render_blocks(array($get_publication_block)));
      }
    }
  }
}

/**
 * Implements theme_menu_link().
 */
function sof_theme_menu_link__main_menu(&$variables) {
  $element = $variables['element'];
  $description = '';
  $sub_menu    = '';
  $depth       = '';

  //Get menu depth
  $depth = $element['#original_link']['depth'];

  //Depth 2 submenu
  //get menu description on level 1
  if ($depth == 1) {
    if($element['#localized_options']){
      $description = isset($element['#localized_options']['attributes']['title']) ?  $element['#localized_options']['attributes']['title'] : '';
    }
    if ($element['#below']) {
      // Wrap in container
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<div class="second-level-main-container">';
    if($description):
        $sub_menu .= '<span class="menu-description">'. $description .'</span>';
    endif;
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

  //Output of main menu
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
* Remove resizable part from textarea
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

  // Return output
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

  //Add Articles/News category
  if(isset($variables['result']['fields']['im_field_category'])){
    $variables['category'] = _sof_category_terms_links($variables['result']['fields']['im_field_category']);
  }
  //Add Publication category
  if(isset($variables['result']['fields']['im_field_category_publication'])){
    $variables['category'] = _sof_category_terms_links($variables['result']['fields']['im_field_category_publication']);
  }
  //Add Section category
  if(isset($variables['result']['fields']['im_field_category_single'])){
    $variables['category'] = _sof_category_terms_links($variables['result']['fields']['im_field_category_single']);
  }
  //Add node teaser instead of snippet
  $variables['teaser'] = $variables['result']['fields']['teaser'];
}

/**
 * Returns HTML for an active facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', 'options', and
 *   'count'. See the l() and theme_facetapi_count() functions for information
 *   about these variables.
 *
 * @ingroup themeable
 */
function sof_theme_facetapi_link_inactive($variables) {
  // Builds accessible markup.
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;
  $output = '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' ;
  $output .= $link_text;
  $output .= '</a>';
  return $output;
}


/**
 * Returns HTML for an inactive facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @ingroup themeable
 */
function sof_theme_facetapi_link_active($variables) {
  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget'),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
 // return theme_facetapi_link($variables) . $link_text;
 // return '<span class="facetapi-element-invisible">' . $link_text . '</span>';
  $output = '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' ;
  $output .= $link_text;
  $output .= '</a>';
  return $output;
}

/**
 * Override or insert variables into the block templates.
 */
function sof_theme_preprocess_block(&$vars) {
  if($vars['elements']['#block']->delta == 'sof_mailchimp_form'){
    $vars['title_prefix'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="mailchimp-signup-sof"><div class="sof_footer_social_media_icon"></div>',
    );
    $vars['title_suffix'] = array(
      '#type' => 'markup',
      '#markup' => '</div>',
    );
  }
}

/**
 * Helper function for generating "Category"(term) links for template_preprocess_search_result()
 *
 * @param $category_field Array
 *  taxonomy term ids of the node
 */
function _sof_category_terms_links($category_field) {
  foreach ($category_field as $key => $value) {
    $term_links[] = array(
      'title' => taxonomy_term_load($value)->name,
      'href'  => 'taxonomy/term/' . $value,
    );
  }
  return theme('links', array(
    'links'      => $term_links,
    'heading'    => array('text' => t('Categories :'), 'level' => 'label'),
    'attributes' => array('class' => array('links', 'inline')),
  ));
}
