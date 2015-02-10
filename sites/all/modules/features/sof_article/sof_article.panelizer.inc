<?php
/**
 * @file
 * sof_article.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function sof_article_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:default:full';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
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
  $display->uuid = '12792635-02ae-4f62-a3a7-682e8a85685a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bdc15f7c-6be5-4a14-bc97-a2cfc74efc8a';
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
    $pane->uuid = 'bdc15f7c-6be5-4a14-bc97-a2cfc74efc8a';
    $display->content['new-bdc15f7c-6be5-4a14-bc97-a2cfc74efc8a'] = $pane;
    $display->panels['bottom'][0] = 'new-bdc15f7c-6be5-4a14-bc97-a2cfc74efc8a';
    $pane = new stdClass();
    $pane->pid = 'new-28a83468-f768-4580-adf5-bd37e8cfafad';
    $pane->panel = 'bottom';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->uuid = '28a83468-f768-4580-adf5-bd37e8cfafad';
    $display->content['new-28a83468-f768-4580-adf5-bd37e8cfafad'] = $pane;
    $display->panels['bottom'][1] = 'new-28a83468-f768-4580-adf5-bd37e8cfafad';
    $pane = new stdClass();
    $pane->pid = 'new-77b26e80-54d5-4a62-9da9-91a97517d2fd';
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
    $pane->uuid = '77b26e80-54d5-4a62-9da9-91a97517d2fd';
    $display->content['new-77b26e80-54d5-4a62-9da9-91a97517d2fd'] = $pane;
    $display->panels['left'][0] = 'new-77b26e80-54d5-4a62-9da9-91a97517d2fd';
    $pane = new stdClass();
    $pane->pid = 'new-9d0afefd-c2dc-4d9b-be83-a0694bd70bd5';
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
    $pane->uuid = '9d0afefd-c2dc-4d9b-be83-a0694bd70bd5';
    $display->content['new-9d0afefd-c2dc-4d9b-be83-a0694bd70bd5'] = $pane;
    $display->panels['left'][1] = 'new-9d0afefd-c2dc-4d9b-be83-a0694bd70bd5';
    $pane = new stdClass();
    $pane->pid = 'new-8c8170d3-ffb6-413e-8c10-767b95b704c0';
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
    $pane->uuid = '8c8170d3-ffb6-413e-8c10-767b95b704c0';
    $display->content['new-8c8170d3-ffb6-413e-8c10-767b95b704c0'] = $pane;
    $display->panels['left'][2] = 'new-8c8170d3-ffb6-413e-8c10-767b95b704c0';
    $pane = new stdClass();
    $pane->pid = 'new-a2cca78d-a21e-4ddd-9455-54ee3d371bdd';
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
    $pane->uuid = 'a2cca78d-a21e-4ddd-9455-54ee3d371bdd';
    $display->content['new-a2cca78d-a21e-4ddd-9455-54ee3d371bdd'] = $pane;
    $display->panels['left'][3] = 'new-a2cca78d-a21e-4ddd-9455-54ee3d371bdd';
    $pane = new stdClass();
    $pane->pid = 'new-d6bee8d9-4c77-4a12-8abb-ac623d568cd6';
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
    $pane->uuid = 'd6bee8d9-4c77-4a12-8abb-ac623d568cd6';
    $display->content['new-d6bee8d9-4c77-4a12-8abb-ac623d568cd6'] = $pane;
    $display->panels['left'][4] = 'new-d6bee8d9-4c77-4a12-8abb-ac623d568cd6';
    $pane = new stdClass();
    $pane->pid = 'new-096676e5-6339-4f91-8935-767166d940c3';
    $pane->panel = 'left';
    $pane->type = 'node_updated';
    $pane->subtype = 'node_updated';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'sof_custom',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Submited on',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '096676e5-6339-4f91-8935-767166d940c3';
    $display->content['new-096676e5-6339-4f91-8935-767166d940c3'] = $pane;
    $display->panels['left'][5] = 'new-096676e5-6339-4f91-8935-767166d940c3';
    $pane = new stdClass();
    $pane->pid = 'new-68fff821-658b-4ae6-b2f8-8024304fbd38';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '68fff821-658b-4ae6-b2f8-8024304fbd38';
    $display->content['new-68fff821-658b-4ae6-b2f8-8024304fbd38'] = $pane;
    $display->panels['left'][6] = 'new-68fff821-658b-4ae6-b2f8-8024304fbd38';
    $pane = new stdClass();
    $pane->pid = 'new-6b22a4d0-b0f2-4aad-98e4-c184b64ce97f';
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
    $pane->uuid = '6b22a4d0-b0f2-4aad-98e4-c184b64ce97f';
    $display->content['new-6b22a4d0-b0f2-4aad-98e4-c184b64ce97f'] = $pane;
    $display->panels['right'][0] = 'new-6b22a4d0-b0f2-4aad-98e4-c184b64ce97f';
    $pane = new stdClass();
    $pane->pid = 'new-a82d0d4c-0b61-49c1-847d-601590803121';
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
    $pane->uuid = 'a82d0d4c-0b61-49c1-847d-601590803121';
    $display->content['new-a82d0d4c-0b61-49c1-847d-601590803121'] = $pane;
    $display->panels['right'][1] = 'new-a82d0d4c-0b61-49c1-847d-601590803121';
    $pane = new stdClass();
    $pane->pid = 'new-fcca162e-78f0-46ed-a514-9eb0f6925f61';
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
      'override_title_text' => 'Related terms',
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
    $pane->uuid = 'fcca162e-78f0-46ed-a514-9eb0f6925f61';
    $display->content['new-fcca162e-78f0-46ed-a514-9eb0f6925f61'] = $pane;
    $display->panels['right'][2] = 'new-fcca162e-78f0-46ed-a514-9eb0f6925f61';
    $pane = new stdClass();
    $pane->pid = 'new-63ae90c3-fcd2-4635-99f7-b477b4657858';
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
    $pane->uuid = '63ae90c3-fcd2-4635-99f7-b477b4657858';
    $display->content['new-63ae90c3-fcd2-4635-99f7-b477b4657858'] = $pane;
    $display->panels['right'][3] = 'new-63ae90c3-fcd2-4635-99f7-b477b4657858';
    $pane = new stdClass();
    $pane->pid = 'new-5914a8c1-edf0-4ec9-9250-81a347a5ee4f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_articles_slider-related_articles_slider_pane';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '5914a8c1-edf0-4ec9-9250-81a347a5ee4f';
    $display->content['new-5914a8c1-edf0-4ec9-9250-81a347a5ee4f'] = $pane;
    $display->panels['right'][4] = 'new-5914a8c1-edf0-4ec9-9250-81a347a5ee4f';
    $pane = new stdClass();
    $pane->pid = 'new-87cb003e-3e63-44a1-883d-b5b370b1d3a7';
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
    $pane->uuid = '87cb003e-3e63-44a1-883d-b5b370b1d3a7';
    $display->content['new-87cb003e-3e63-44a1-883d-b5b370b1d3a7'] = $pane;
    $display->panels['right'][5] = 'new-87cb003e-3e63-44a1-883d-b5b370b1d3a7';
    $pane = new stdClass();
    $pane->pid = 'new-9b07142a-1ed5-4962-b8ee-310b1687f0d5';
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
        'links' => TRUE,
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
    $pane->uuid = '9b07142a-1ed5-4962-b8ee-310b1687f0d5';
    $display->content['new-9b07142a-1ed5-4962-b8ee-310b1687f0d5'] = $pane;
    $display->panels['right'][6] = 'new-9b07142a-1ed5-4962-b8ee-310b1687f0d5';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:article:default:full'] = $panelizer;

  return $export;
}
