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
  $handler->display->display_options['fields']['field_teaser']['alter']['max_length'] = '200';
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
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: News deck latest 3 news */
  $handler = $view->new_display('panel_pane', 'News deck latest 3 news', 'news_deck_latest_three_news');
  $handler->display->display_options['display_description'] = 'Will show latest 3 news for the news deck';
  $export['news_deck_latest_3_nodes'] = $view;

  $view = new view();
  $view->name = 'other_releases';
  $view->description = 'Block on the bottom of the publications. Lists 4 latest publications of the same category';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Other releases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Other releases';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Publication category relationship */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['ui_name'] = 'Publication category relationship';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'publication_category';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'publication_category' => 'publication_category',
    'general_category' => 0,
    'magazine_categories' => 0,
    'media_folders' => 0,
    'tags' => 0,
  );
  /* Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['ui_name'] = 'Image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'publication_related',
    'image_link' => '',
  );
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
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
    'publication_category' => 'publication_category',
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
    'publication' => 'publication',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Other releases */
  $handler = $view->new_display('block', 'Other releases', 'block');
  $handler->display->display_options['display_description'] = '4 latest publications of the same category';
  $export['other_releases'] = $view;

  $view = new view();
  $view->name = 'publication_listing_view';
  $view->description = 'Publication listing from the Apachesolr index';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Publication listing view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Url(not shown) */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['ui_name'] = 'Url(not shown)';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  /* Field: Image */
  $handler->display->display_options['fields']['sm_thumb_publication_related_field_image']['id'] = 'sm_thumb_publication_related_field_image';
  $handler->display->display_options['fields']['sm_thumb_publication_related_field_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_publication_related_field_image']['field'] = 'sm_thumb_publication_related_field_image';
  $handler->display->display_options['fields']['sm_thumb_publication_related_field_image']['ui_name'] = 'Image';
  $handler->display->display_options['fields']['sm_thumb_publication_related_field_image']['label'] = '';
  $handler->display->display_options['fields']['sm_thumb_publication_related_field_image']['element_label_colon'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Teaser */
  $handler->display->display_options['fields']['teaser']['id'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['teaser']['field'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['ui_name'] = 'Teaser';
  $handler->display->display_options['fields']['teaser']['label'] = '';
  $handler->display->display_options['fields']['teaser']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['teaser']['element_label_colon'] = FALSE;
  /* Sort criterion: Apache Solr: ds_changed */
  $handler->display->display_options['sorts']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['order'] = 'DESC';
  /* Contextual filter: Apache Solr: content */
  $handler->display->display_options['arguments']['content']['id'] = 'content';
  $handler->display->display_options['arguments']['content']['table'] = 'apachesolr__solr';
  $handler->display->display_options['arguments']['content']['field'] = 'content';
  $handler->display->display_options['arguments']['content']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['content']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['content']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['content']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['content']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['content']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['content']['validate_options']['code'] = 'return $argument ? true : false;';
  $handler->display->display_options['arguments']['content']['validate']['fail'] = 'ignore';
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'publication';
  $handler->display->display_options['filters']['bundle']['group'] = 1;

  /* Display: Grid listing publication page */
  $handler = $view->new_display('panel_pane', 'Grid listing publication page', 'grid_listing_publication');
  $handler->display->display_options['display_description'] = 'List of publications as greed 2x4. Image, title and teaser';
  $handler->display->display_options['argument_input'] = array(
    'content' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Panel context argument',
    ),
  );
  $export['publication_listing_view'] = $view;

  $view = new view();
  $view->name = 'read_also';
  $view->description = 'Block on the bottom of the articles/news. Two random related articles/news on the left side of the bottom region';
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
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['read_also'] = $view;

  $view = new view();
  $view->name = 'recommended_items_overview';
  $view->description = 'Attached on recommended items deck as extra filed. Listing max 20 links to nodes from same category.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recommended items overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Overview';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
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
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
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
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Recommended items overview */
  $handler = $view->new_display('panel_pane', 'Recommended items overview', 'recommended_items_overview');
  $handler->display->display_options['display_description'] = 'List random 20 links to a nodes connected with "General category" vocabular with this section';
  $export['recommended_items_overview'] = $view;

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
  $view->description = 'Block on the article/news page with links to related articles/news related by \'Global category\'';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
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
    'magazine_categories' => 0,
    'media_folders' => 0,
    'publication_category' => 0,
    'tags' => 0,
  );
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_category_single_node';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_category_single_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'news' => 'news',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

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
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
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
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

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

  $view = new view();
  $view->name = 'we_are_writing_about_additional_displays';
  $view->description = 'Two additional listings for the "We are writing about deck". Most popular (ga_stats) and Latest updated.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'We are writing about additional displays';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
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
    'section' => 'section',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Latest updated */
  $handler = $view->new_display('panel_pane', 'Latest updated', 'latest_updated');
  $handler->display->display_options['display_description'] = 'Links to latest 4 last updated nodes';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Header latest updated display */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['ui_name'] = 'Header latest updated display';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'we_are_writing_about_additional_displays:header_latest_updated';

  /* Display: Header latest updated */
  $handler = $view->new_display('panel_pane', 'Header latest updated', 'header_latest_updated');
  $handler->display->display_options['display_description'] = 'Latest updated node for header in latest updated';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Image (article, news) */
  $handler->display->display_options['fields']['field_image_slider']['id'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['table'] = 'field_data_field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['field'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['ui_name'] = 'Image (article, news)';
  $handler->display->display_options['fields']['field_image_slider']['label'] = '';
  $handler->display->display_options['fields']['field_image_slider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_slider']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_slider']['settings'] = array(
    'image_style' => 'article_top_slider',
    'image_link' => 'content',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_image_slider']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image_slider']['delta_offset'] = '0';
  /* Field: Image (section) */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['ui_name'] = 'Image (section)';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'article_top_slider',
    'image_link' => 'content',
  );
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;

  /* Display: Most popular */
  $handler = $view->new_display('panel_pane', 'Most popular', 'most_popular');
  $handler->display->display_options['display_description'] = 'Links to latest 4 most popular nodes (ga_stats)';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Header most popular display */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['ui_name'] = 'Header most popular display';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'we_are_writing_about_additional_displays:header_most_popular';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Statistics: Page Views in the past 31 days */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'ga_stats_count_pageviews_month';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['order'] = 'DESC';

  /* Display: Header most popular */
  $handler = $view->new_display('panel_pane', 'Header most popular', 'header_most_popular');
  $handler->display->display_options['display_description'] = 'Most popular node for header in most popular';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Image (section) */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['ui_name'] = 'Image (section)';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'article_top_slider',
    'image_link' => 'content',
  );
  /* Field: Image (article, news) */
  $handler->display->display_options['fields']['field_image_slider']['id'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['table'] = 'field_data_field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['field'] = 'field_image_slider';
  $handler->display->display_options['fields']['field_image_slider']['ui_name'] = 'Image (article, news)';
  $handler->display->display_options['fields']['field_image_slider']['label'] = '';
  $handler->display->display_options['fields']['field_image_slider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_slider']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_slider']['settings'] = array(
    'image_style' => 'article_top_slider',
    'image_link' => 'content',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_image_slider']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image_slider']['delta_offset'] = '0';
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Statistics: Page Views in the past 31 days */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'ga_stats_count_pageviews_month';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['order'] = 'DESC';
  $export['we_are_writing_about_additional_displays'] = $view;

  return $export;
}
