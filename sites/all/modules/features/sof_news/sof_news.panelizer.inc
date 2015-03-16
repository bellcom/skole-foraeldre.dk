<?php
/**
 * @file
 * sof_news.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function sof_news_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:news:default:full';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'news';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'full';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'sof-news-articles';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '31cd3ba4-c007-4f93-9b6c-537c845bde22';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-daaf12c2-13c7-4437-acb7-f074aff1a588';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'read_also-read_also_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'daaf12c2-13c7-4437-acb7-f074aff1a588';
    $display->content['new-daaf12c2-13c7-4437-acb7-f074aff1a588'] = $pane;
    $display->panels['bottom'][0] = 'new-daaf12c2-13c7-4437-acb7-f074aff1a588';
    $pane = new stdClass();
    $pane->pid = 'new-7f27d182-b967-4ab4-86f9-9c0bffc84437';
    $pane->panel = 'bottom';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'link_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7f27d182-b967-4ab4-86f9-9c0bffc84437';
    $display->content['new-7f27d182-b967-4ab4-86f9-9c0bffc84437'] = $pane;
    $display->panels['bottom'][1] = 'new-7f27d182-b967-4ab4-86f9-9c0bffc84437';
    $pane = new stdClass();
    $pane->pid = 'new-9dd5050b-52f2-469c-bc1f-e1a50158e216';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image_slider';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'flexslider',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'caption' => 1,
        'field_multiple_limit' => -1,
        'field_multiple_limit_offset' => 0,
        'image_style' => 'flexslider_full',
        'optionset' => 'sof_field',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9dd5050b-52f2-469c-bc1f-e1a50158e216';
    $display->content['new-9dd5050b-52f2-469c-bc1f-e1a50158e216'] = $pane;
    $display->panels['left'][0] = 'new-9dd5050b-52f2-469c-bc1f-e1a50158e216';
    $pane = new stdClass();
    $pane->pid = 'new-9b4c7da8-59cd-4104-b1c1-d97492b4e42d';
    $pane->panel = 'left';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9b4c7da8-59cd-4104-b1c1-d97492b4e42d';
    $display->content['new-9b4c7da8-59cd-4104-b1c1-d97492b4e42d'] = $pane;
    $display->panels['left'][1] = 'new-9b4c7da8-59cd-4104-b1c1-d97492b4e42d';
    $pane = new stdClass();
    $pane->pid = 'new-7a798968-a9ac-4c81-a7db-58c81614bd2b';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_teaser';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_multiple_limit' => -1,
        'field_multiple_limit_offset' => 0,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7a798968-a9ac-4c81-a7db-58c81614bd2b';
    $display->content['new-7a798968-a9ac-4c81-a7db-58c81614bd2b'] = $pane;
    $display->panels['left'][2] = 'new-7a798968-a9ac-4c81-a7db-58c81614bd2b';
    $pane = new stdClass();
    $pane->pid = 'new-86e74420-b30f-4f91-8f94-b0c52761b68c';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_multiple_limit' => -1,
        'field_multiple_limit_offset' => 0,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '86e74420-b30f-4f91-8f94-b0c52761b68c';
    $display->content['new-86e74420-b30f-4f91-8f94-b0c52761b68c'] = $pane;
    $display->panels['left'][3] = 'new-86e74420-b30f-4f91-8f94-b0c52761b68c';
    $pane = new stdClass();
    $pane->pid = 'new-37313fd2-c6a6-4976-9909-0da21bd95096';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_video';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'media',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_multiple_limit' => -1,
        'field_multiple_limit_offset' => 0,
        'file_view_mode' => 'full',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '37313fd2-c6a6-4976-9909-0da21bd95096';
    $display->content['new-37313fd2-c6a6-4976-9909-0da21bd95096'] = $pane;
    $display->panels['left'][4] = 'new-37313fd2-c6a6-4976-9909-0da21bd95096';
    $pane = new stdClass();
    $pane->pid = 'new-a6c76b9e-cea6-464a-a133-d6b82b5d5e8f';
    $pane->panel = 'left';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'sof_custom',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Submitted on',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-node-updated',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'a6c76b9e-cea6-464a-a133-d6b82b5d5e8f';
    $display->content['new-a6c76b9e-cea6-464a-a133-d6b82b5d5e8f'] = $pane;
    $display->panels['left'][5] = 'new-a6c76b9e-cea6-464a-a133-d6b82b5d5e8f';
    $pane = new stdClass();
    $pane->pid = 'new-fb578095-9fe7-4be0-bda5-8c0aa3d04b42';
    $pane->panel = 'left';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'by',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-node-author',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'fb578095-9fe7-4be0-bda5-8c0aa3d04b42';
    $display->content['new-fb578095-9fe7-4be0-bda5-8c0aa3d04b42'] = $pane;
    $display->panels['left'][6] = 'new-fb578095-9fe7-4be0-bda5-8c0aa3d04b42';
    $pane = new stdClass();
    $pane->pid = 'new-c3f11bad-12fd-4bcc-b100-3c27facb27e9';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_publication_control_link';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c3f11bad-12fd-4bcc-b100-3c27facb27e9';
    $display->content['new-c3f11bad-12fd-4bcc-b100-3c27facb27e9'] = $pane;
    $display->panels['right'][0] = 'new-c3f11bad-12fd-4bcc-b100-3c27facb27e9';
    $pane = new stdClass();
    $pane->pid = 'new-a0834002-1e79-4c81-93a2-1baeac8a62b2';
    $pane->panel = 'right';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:download_as_pdf';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a0834002-1e79-4c81-93a2-1baeac8a62b2';
    $display->content['new-a0834002-1e79-4c81-93a2-1baeac8a62b2'] = $pane;
    $display->panels['right'][1] = 'new-a0834002-1e79-4c81-93a2-1baeac8a62b2';
    $pane = new stdClass();
    $pane->pid = 'new-003639f4-904b-4bdb-bb2d-fd542a5d74af';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_terms';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:article:field_set_rt_manually',
          'settings' => array(
            'field_set_rt_manually' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_set_rt_manually_value' => '1',
          ),
          'context' => 'panelizer',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
        'field_multiple_limit' => '-1',
        'field_multiple_limit_offset' => '0',
      ),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Related topics',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '003639f4-904b-4bdb-bb2d-fd542a5d74af';
    $display->content['new-003639f4-904b-4bdb-bb2d-fd542a5d74af'] = $pane;
    $display->panels['right'][2] = 'new-003639f4-904b-4bdb-bb2d-fd542a5d74af';
    $pane = new stdClass();
    $pane->pid = 'new-fabadb57-ef63-403e-ab6d-cfacad9144ba';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_content-related_terms_pane';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:article:field_set_rt_manually',
          'settings' => array(
            'field_set_rt_manually' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_set_rt_manually_value' => '1',
          ),
          'context' => 'panelizer',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'fabadb57-ef63-403e-ab6d-cfacad9144ba';
    $display->content['new-fabadb57-ef63-403e-ab6d-cfacad9144ba'] = $pane;
    $display->panels['right'][3] = 'new-fabadb57-ef63-403e-ab6d-cfacad9144ba';
    $pane = new stdClass();
    $pane->pid = 'new-266c3cbf-8ba7-4038-8bfb-6372dd9ca0b3';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_articles_slider-related_news_slider_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '266c3cbf-8ba7-4038-8bfb-6372dd9ca0b3';
    $display->content['new-266c3cbf-8ba7-4038-8bfb-6372dd9ca0b3'] = $pane;
    $display->panels['right'][4] = 'new-266c3cbf-8ba7-4038-8bfb-6372dd9ca0b3';
    $pane = new stdClass();
    $pane->pid = 'new-02ad3f73-c9e3-4cab-9ad8-78422aad899f';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_multiple_limit' => -1,
        'field_multiple_limit_offset' => 0,
        'links' => 1,
        'view_mode' => 'related_content_reference',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '02ad3f73-c9e3-4cab-9ad8-78422aad899f';
    $display->content['new-02ad3f73-c9e3-4cab-9ad8-78422aad899f'] = $pane;
    $display->panels['right'][5] = 'new-02ad3f73-c9e3-4cab-9ad8-78422aad899f';
    $pane = new stdClass();
    $pane->pid = 'new-132a2664-c3c1-4cc2-ae8b-68a113a9d7ad';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_banner';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_multiple_limit' => -1,
        'field_multiple_limit_offset' => 0,
        'links' => 1,
        'view_mode' => 'default',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '132a2664-c3c1-4cc2-ae8b-68a113a9d7ad';
    $display->content['new-132a2664-c3c1-4cc2-ae8b-68a113a9d7ad'] = $pane;
    $display->panels['right'][6] = 'new-132a2664-c3c1-4cc2-ae8b-68a113a9d7ad';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:news:default:full'] = $panelizer;

  return $export;
}
