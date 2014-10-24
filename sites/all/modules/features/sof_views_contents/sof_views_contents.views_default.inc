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
  $view->name = 'news_deck_latest_3_nodes';
  $view->description = 'Lists latest 3 news for the bottom part of the news deck';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News deck latest 3 news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['ui_name'] = 'Teaser';
  $handler->display->display_options['fields']['field_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['type'] = 'text_plain';
  /* Field: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'news' => 'news',
  );

  /* Display: News deck latest 3 news */
  $handler = $view->new_display('panel_pane', 'News deck latest 3 news', 'news_deck_latest_three_news');
  $handler->display->display_options['display_description'] = 'Will show latest 3 news for the news deck';
  $export['news_deck_latest_3_nodes'] = $view;

  $view = new view();
  $view->name = 'read_also';
  $view->description = 'Block on the bottom of the articles/news. Two random related articles(left) and categories with links to section pages(right).';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Read also';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'media_folders' => 0,
    'publication_category' => 0,
    'tags' => 0,
  );
  /* Field: Image */
  $handler->display->display_options['fields']['field_image_slider']['id'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['table'] = 'field_data_field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['field'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['ui_name'] = 'Image';
  $handler->display->display_options['fields']['field_image_slider']['label'] = '';
  $handler->display->display_options['fields']['field_image_slider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_slider']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_slider']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_slider']['settings'] = array(
    'image_style' => 'related_content_reference_image',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_slider']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image_slider']['delta_offset'] = '0';
  /* Field: Date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['ui_name'] = 'Teaser';
  $handler->display->display_options['fields']['field_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_teaser']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['field_teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['type'] = 'text_plain';
  /* Field: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'general_category' => 'general_category',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
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
    'news' => 'news',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['read_also'] = $view;

  $view = new view();
  $view->name = 'related_articles_slider';
  $view->description = 'Small slider used on article or news page for showing related content as slider of the same type.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related articles-news slider (Also see block)';
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
  $handler->display->display_options['fields']['title']['ui_name'] = '(not shown) Slide caption';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Slide image */
  $handler->display->display_options['fields']['field_image_slider_1']['id'] = 'field_image_slider_1';
  $handler->display->display_options['fields']['field_image_slider_1']['table'] = 'field_data_field_image_slider';
  $handler->display->display_options['fields']['field_image_slider_1']['field'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider_1']['relationship'] = 'field_related_news_target_id';
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
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Related news (field_related_news:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_related_news';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['operator'] = 'not empty';
  $handler->display->display_options['filters']['delta']['group'] = 2;
  /* Filter criterion: Content: Related articles (field_related_article) */
  $handler->display->display_options['filters']['field_related_article_target_id']['id'] = 'field_related_article_target_id';
  $handler->display->display_options['filters']['field_related_article_target_id']['table'] = 'field_data_field_related_article';
  $handler->display->display_options['filters']['field_related_article_target_id']['field'] = 'field_related_article_target_id';
  $handler->display->display_options['filters']['field_related_article_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_related_article_target_id']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_news_target_id']['id'] = 'field_related_news_target_id';
  $handler->display->display_options['relationships']['field_related_news_target_id']['table'] = 'field_data_field_related_news';
  $handler->display->display_options['relationships']['field_related_news_target_id']['field'] = 'field_related_news_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: (not shown) Slide caption */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_news_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = '(not shown) Slide caption';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Slide image */
  $handler->display->display_options['fields']['field_image_slider_1']['id'] = 'field_image_slider_1';
  $handler->display->display_options['fields']['field_image_slider_1']['table'] = 'field_data_field_image_slider';
  $handler->display->display_options['fields']['field_image_slider_1']['field'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider_1']['relationship'] = 'field_related_news_target_id';
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

  $view = new view();
  $view->name = 'section_default_content';
  $view->description = 'Contains 2 displays for default content on the section page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Section default content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'section-header';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'media_folders' => 0,
    'publication_category' => 0,
    'tags' => 0,
  );
  /* Field: Image */
  $handler->display->display_options['fields']['field_image_slider']['id'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['table'] = 'field_data_field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['field'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['ui_name'] = 'Image';
  $handler->display->display_options['fields']['field_image_slider']['label'] = '';
  $handler->display->display_options['fields']['field_image_slider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_slider']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_slider']['settings'] = array(
    'image_style' => 'related_content_reference_image',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_slider']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image_slider']['delta_offset'] = '0';
  /* Field: Date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['ui_name'] = 'Teaser';
  $handler->display->display_options['fields']['field_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['type'] = 'text_plain';
  /* Field: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'general_category' => 'general_category',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'news' => 'news',
  );

  /* Display: Section header */
  $handler = $view->new_display('panel_pane', 'Section header', 'section_default_header');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'section-header';
  $handler->display->display_options['display_description'] = 'Highlighted latest 3 published nodes';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Image */
  $handler->display->display_options['fields']['field_image_slider']['id'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['table'] = 'field_data_field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['field'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['ui_name'] = 'Image';
  $handler->display->display_options['fields']['field_image_slider']['label'] = '';
  $handler->display->display_options['fields']['field_image_slider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_slider']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_slider']['settings'] = array(
    'image_style' => 'related_content_reference_image',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_slider']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image_slider']['delta_offset'] = '0';
  /* Field: Date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['ui_name'] = 'Teaser';
  $handler->display->display_options['fields']['field_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_teaser']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_teaser']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['type'] = 'text_plain';
  /* Field: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';

  /* Display: Section default listings */
  $handler = $view->new_display('panel_pane', 'Section default listings', 'section_default_listing');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'section-default-listiing';
  $handler->display->display_options['display_description'] = 'List of all nodes(exept last 3 from the header) conected to the section by "Genral category" term';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '3';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['ui_name'] = 'Teaser';
  $handler->display->display_options['fields']['field_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_teaser']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['type'] = 'text_plain';
  $export['section_default_content'] = $view;

  return $export;
}
