<?php
/**
 * @file
 * sof_views_contents.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sof_views_contents_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'related_articles_slider';
  $view->description = 'Small slider used on article page for showing related artilcles.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related articles slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Also see';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['captionfield'] = 'title';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content entity referenced from field_related_article */
  $handler->display->display_options['relationships']['field_related_article_target_id']['id'] = 'field_related_article_target_id';
  $handler->display->display_options['relationships']['field_related_article_target_id']['table'] = 'field_data_field_related_article';
  $handler->display->display_options['relationships']['field_related_article_target_id']['field'] = 'field_related_article_target_id';
  $handler->display->display_options['relationships']['field_related_article_target_id']['ui_name'] = 'Content entity referenced from field_related_article';
  /* Field: (not shown) Slide caption */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_article_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = '(not shown) Slide caption';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Slide image */
  $handler->display->display_options['fields']['field_image_slider_1']['id'] = 'field_image_slider_1';
  $handler->display->display_options['fields']['field_image_slider_1']['table'] = 'field_data_field_image_slider';
  $handler->display->display_options['fields']['field_image_slider_1']['field'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider_1']['relationship'] = 'field_related_article_target_id';
  $handler->display->display_options['fields']['field_image_slider_1']['ui_name'] = 'Slide image';
  $handler->display->display_options['fields']['field_image_slider_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_slider_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_slider_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_slider_1']['settings'] = array(
    'image_style' => 'article_top_slider',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image_slider_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image_slider_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_image_slider_1']['multi_type'] = 'ul';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['related_articles_slider'] = $view;

  $view = new view();
  $view->name = 'related_content';
  $view->description = 'Block on the article page with links to section pages conected to the article by terms';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: General category relationship */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['ui_name'] = 'General category relationship';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'general_category';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'general_category' => 'general_category',
    'publication_category' => 0,
    'tags' => 0,
  );
  /* Relationship: Nodes using category relationship */
  $handler->display->display_options['relationships']['reverse_field_category_single_node']['id'] = 'reverse_field_category_single_node';
  $handler->display->display_options['relationships']['reverse_field_category_single_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_category_single_node']['field'] = 'reverse_field_category_single_node';
  $handler->display->display_options['relationships']['reverse_field_category_single_node']['relationship'] = 'term_node_tid';
  $handler->display->display_options['relationships']['reverse_field_category_single_node']['ui_name'] = 'Nodes using category relationship';
  /* Field: (not shown) Section id */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_category_single_node';
  $handler->display->display_options['fields']['nid']['ui_name'] = '(not shown) Section id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: General category term name with link to section */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['name']['ui_name'] = 'General category term name with link to section';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'sektion/[nid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['related_content'] = $view;

  return $export;
}
