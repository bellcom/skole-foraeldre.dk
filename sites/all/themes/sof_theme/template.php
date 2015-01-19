<?php

/**
 * @file
 * Process theme data.
 */

/**
 * Preprocess variables for the html template.
 */
function sof_theme_preprocess_html(&$vars) {
  // Add body class when page is not found  or access id denided.
  $status = drupal_get_http_header("status");
  if (($status == '404 Not Found') || ($status == '403 Forbidden')) {
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
  $theme = "sof_theme";
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
    // If toggle_site_slogan is FALSE, the site_slogan will be empty.
    // so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    // Add a wrapper div using the title_prefix and title_suffix.
    // render elements.
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
  // Add theme hook suggestion for search page.
  if (arg(0) == 'search' && arg(1) && arg(2)) {
    $variables['theme_hook_suggestions'][] = 'page__search';
  }
  if ($variables['theme_hook_suggestions'][0] == 'page__taxonomy') {
    $variables['theme_hook_suggestions'][] = 'page__search';
  }
  // Default footer logo image.
  $default_footerlogo_image = $base_path . drupal_get_path('theme', $theme) . '/footer_logo.png';
  // Footer logo image that Theme Settings.
  $footerlogo_image = theme_get_setting('footerlogo_image', $theme);
  $variables['footerlogo_image'] = file_create_url(!empty($footerlogo_image) ? $footerlogo_image : $default_footerlogo_image);
  $variables['footerlogo_image'] = file_create_url($footerlogo_image);
}

/**
 * Override related content field in article node.
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
 * Override field field_video.
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
 * Override field.
 */
function sof_theme_preprocess_field(&$vars) {
  if ($vars['element']['#field_name'] == 'commerce_price') {
    $vars['label_hidden'] = TRUE;
  }
  global $base_path;
  $element = $vars['element'];
  if ($element['#field_name'] == 'field_we_recommend_reference') {
    $nid = key($element['#items']);
    $title = $element['#object']->field_we_recommend_reference['und'][$nid]['entity']->title;
    $linktonode = $element['#items'][$nid]['entity']->vid;
    $vars['nodecustomlink'] = l($title, '/node/' . $linktonode . '', array(
      'attributes' => array(
        'class' => array('node-title-werecommend'),
      ),
      'fragment' => '',
      'external' => TRUE,
    ));
  }
  // Magazine Deck fields preprocess: Field Category title.
  if ($element['#field_name'] == 'field_small_title' && $element['#bundle'] == 'field_magazine_category') {
    $vars['items'][0]['#prefix'] = '<a class="mag-deck-default" href="http://www.skoleborn.dk/" target="_blank">';
    $vars['items'][0]['#suffix'] = '</a>';
  }
  // Magazine Deck fields preprocess: Field Image.
  if ($element['#field_name'] == 'field_image' && $element['#bundle'] == 'magazine_pane') {
    $vars['items'][0]['#prefix'] = '<a class="mag-deck-default" href="http://www.skoleborn.dk/" target="_blank">';
    $vars['items'][0]['#suffix'] = '</a>';
  }

  // Block: Related Content Single Block.
  if ($element['#field_type'] == 'image') {
    // Reduce number of images in related content reference.
    // view mode to single image.
    if ($element['#view_mode'] == 'related_content_reference') {
      $item = reset($vars['items']);
      $vars['items'] = array($item);
    }
  }
  // Banner deck settings.
  // Display banner icon as image.
  if ($element['#field_name'] == 'field_icon' && $element['#entity_type'] == 'field_collection_item') {
    $machine_value = $element['#items'][0]['value'];
    $icon_link = $base_path . drupal_get_path('theme', 'sof_theme') . '/css/images/banner_deck_images/icon_' . $machine_value . '.svg';
    $vars['element'][0]['#markup'] = '<img class="banner-deck-icon" alt="' . $machine_value . '" src="' . $icon_link . '"  />';
    $vars['items'][0]['#markup'] = '<img class="banner-deck-icon" alt="' . $machine_value . '" src="' . $icon_link . '" />';
  }
}

/**
 * Preprocess function for form .
 */
function sof_theme_form_alter(&$form, &$form_state, $form_id) {
  // Add placeholder to search page block.
  $form['basic']['keys']['#attributes']['placeholder'] = t('Search');
  // Add placeholder to publuication listing page search block.
  $form['apachesolr_panels_search_form']['#attributes']['placeholder'] = t('Search within publications');
}

/**
 * Preprocess function for fieldable-panels-pane.tpl.php.
 */
function sof_theme_preprocess_fieldable_panels_pane(&$variables) {

  global $base_path;
  $fieldable_pane_type = $variables['elements']['#bundle'];
  // Add title on every deck.
  switch ($fieldable_pane_type) {
    case 'news_pane':{

      $variables['panetitle'] = $variables['elements']['#fieldable_panels_pane']->title;

      // Follow site block.
      if ($get_follow_site_block = block_load('follow', 'site')) {
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
      if (!empty($variables['elements']['#fieldable_panels_pane']->title)) {
        $variables['title'] = $variables['elements']['#fieldable_panels_pane']->title;
      }

      // Add background variable.
      if (isset($variables['field_background_image'])) {
        $variables['magazine_background'] = image_style_url('magazine_deck_background', $variables['field_background_image'][0]['uri']);
        hide($variables['content']['field_background_image']);
      }
      else {
        $variables['magazine_background'] = $base_path . drupal_get_path('theme', 'sof_theme') . '/css/images/magazine-deck-bg.jpg';
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

  // Add theme sugestions for publication.
  if ($node->type == 'publication') {
    $variables['theme_hook_suggestion'] = 'node__publication__full';
    // Add new variable if publication has one product .
    if (count($variables['field_sof_commerce_product']) === 1) {
      $variables['oneproduct'] = 'publication-oneproduct';
    }
    else {
      $variables['oneproduct'] = ' ';
    }
  }

  // Add theme sugestions for news and articles.
  if ($node->type == 'news' || $node->type == 'article') {
    if ($view_mode == 'teaser') {
      $variables['content']['field_teaser'][0]['#markup'] = truncate_utf8($variables['content']['field_teaser'][0]['#markup'], 320, FALSE, TRUE);
    }
    if ($view_mode == 'full') {
      $variables['theme_hook_suggestion'] = 'node__articlenews__full';
      // Add print button link.
      $variables['print_button'] = l(t('Print'), 'javascript:window.print()', array(
        'attributes' => array(
          'class' => array('print-btn'),
        ),
        'fragment' => '',
        'external' => TRUE,
      ));
      // Publication link variable.
      if ($variables['field_publication_control_link'][LANGUAGE_NONE][0]['value'] == 1) {
        $variables['publication_link'] = l(t('See all publications'), 'releases', array(
          'attributes' => array(
            'class' => array('publications-btn'),
          ),
           'fragment' => '',
        ));
      }

      // Related terms block.
      if (!empty($variables['field_set_rt_manually']) && $variables['field_set_rt_manually'][LANGUAGE_NONE][0]['value'] == TRUE) {
        $variables['content']['field_related_terms']['#title'] = t('Related content');
      }
      else {
        // Hide manually set related terms.
        $variables['content']['field_related_terms']['#access'] = FALSE;

        // Related terms view block.
        if ($get_related_block = block_load('views', 'related_content-block')) {
          $variables['blockrelatedterms'] = _block_get_renderable_array(_block_render_blocks(array($get_related_block)));
        }

      }
      // Related articles/news slideshow.
      if ($get_slider_block = block_load('views', $node->type == 'article' ? 'related_articles_slider-block' : 'related_articles_slider-block_1')) {
        $variables['blockrelatedslider'] = _block_get_renderable_array(_block_render_blocks(array($get_slider_block)));
      }
      // Read Also Content.
      if ($get_read_also_block = block_load('views', 'read_also-block')) {
        $variables['blockrelatedcontent'] = _block_get_renderable_array(_block_render_blocks(array($get_read_also_block)));
      }
      // Alter submited by author.
      $user = user_load($variables['uid']);
      $variables['submitted'] = t('Submitted on !datetime by !username',
        array(
          '!datetime' => format_date($node->type == 'article' ? $variables['changed'] : $variables['created'], 'sof_custom'),
          '!username' => l($user->name, 'mailto:' . $user->mail, array('absolute' => TRUE)),
        ));
    }
    // Realted Articles Side Block display.
    elseif ($view_mode == 'related_content_reference') {
      $variables['theme_hook_suggestion'] = 'node__article__related_content_reference';
    }
    // News Deck top article display.
    elseif ($view_mode == 'primary_selected_node') {
      $variables['content']['field_teaser'][0]['#markup'] = truncate_utf8($variables['content']['field_teaser'][0]['#markup'], 500, FALSE, TRUE);
      $variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
      $variables['theme_hook_suggestion'] = 'node__news__newsdeck';
    }
    // See also deck display.
    elseif ($view_mode == 'teaser') {
      $variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
      $variables['theme_hook_suggestion'] = 'node__seealso_deck';
    }
    // Video Deck display.
    elseif ($view_mode == 'video_reference_listing') {
      $variables['submitted'] = format_date($variables['changed'], 'custom', 'd.m.y');
      $variables['theme_hook_suggestion'] = 'node__video_reference';
    }
    // Link to nodes display.
    elseif ($view_mode == 'links_to_nodes') {
      $variables['submitted'] = FALSE;
    }
  }
  // Realted Publication Side Block display.
  if ($node->type == 'publication') {
    if ($view_mode == 'related_content_reference') {
      $variables['theme_hook_suggestion'] = 'node__article__related_content_reference';
    }
    // Add variable with related publications block.
    if ($view_mode == 'full') {
      if ($get_publication_block = block_load('views', 'other_releases-block')) {
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

  // Get menu depth.
  $depth = $element['#original_link']['depth'];

  // Depth 2 submenu.
  // get menu description on level 1
  if ($depth == 1) {
    if ($element['#localized_options']) {
      $description = isset($element['#localized_options']['attributes']['title']) ? $element['#localized_options']['attributes']['title'] : '';
    }
    if ($element['#below']) {
      // Wrap in container.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<div class="second-level-main-container">';
      if ($description):
        $sub_menu .= '<span class="menu-description">' . $description . '</span>';
      endif;
      $sub_menu .= '<ul class="second-level">' . drupal_render($element['#below']) . '</ul>';
      $sub_menu .= '</div>';
    }
  }

  // Depth 2 submenu.
  if ($depth == 2) {
    if ($element['#below']) {
      // Wrap in container.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<div class="third-level-main-container">';
      $sub_menu .= '<ul class="third-level">' . drupal_render($element['#below']) . '</ul>';
      $sub_menu .= '</div>';
    }
  }

  // Output of main menu.
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Remove resizable part from textarea.
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

  // Return output.
  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

/**
 * Preprocess search page result.
 *
 * @see template_preprocess_search_result()
 */
function sof_theme_preprocess_search_result(&$variables) {
  unset($variables['info_split']['user']);

  // Add Articles/News category.
  if (isset($variables['result']['fields']['im_field_category'])) {
    $variables['category'] = _sof_category_terms_links($variables['result']['fields']['im_field_category']);
  }
  // Add Publication category.
  if (isset($variables['result']['fields']['im_field_category_publication'])) {
    $variables['category'] = _sof_category_terms_links($variables['result']['fields']['im_field_category_publication']);
  }
  // Add Section category.
  if (isset($variables['result']['fields']['im_field_category_single'])) {
    $variables['category'] = _sof_category_terms_links($variables['result']['fields']['im_field_category_single']);
  }

  // Add node teaser instead of snippet.
  $variables['teaser'] = truncate_utf8($variables['result']['fields']['ts_node_teaser'], 300, TRUE, TRUE);
}

/**
 * Returns HTML for an active facet item.
 *
 * An associative array containing the keys 'text', 'path', 'options', and
 * 'count'. See the l() and theme_facetapi_count() functions for information
 * about these variables.
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
  $output = '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>';
  $output .= $link_text;
  $output .= '</a>';
  return $output;
}


/**
 * Returns HTML for an inactive facet item.
 *
 *   $variables
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
  $output = '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>';
  $output .= $link_text;
  $output .= '</a>';
  return $output;
}

/**
 * Override or insert variables into the block templates.
 */
function sof_theme_preprocess_block(&$vars) {
  if ($vars['elements']['#block']->delta == 'sof_mailchimp_form') {
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
 * Cusotm function for links to terms search page.
 *
 * @param array $category_field
 *   term refference field value for node categories
 */
function _sof_category_terms_links($category_field) {

  $term_links = array();

  foreach ($category_field as $key => $value) {
    $term_obj = taxonomy_term_load($value);
    if ($term_obj) {
      $term_links[] = array(
        'title' => taxonomy_term_load($value)->name,
        'href'  => 'taxonomy/term/' . $value,
      );
    }
  }

  return theme('links', array(
    'links'      => $term_links,
    'heading'    => array('text' => t('Categories :'), 'level' => 'label'),
    'attributes' => array('class' => array('links', 'inline')),
  ));
}
