<?php
/**
 * @file
 * sof_section.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function sof_section_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:section:default:full';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'section';
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
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'ea08c781-af1e-4e36-97d4-f34cd31e5762';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bc08a14f-2055-4f39-96be-b7b11bf1a350';
    $pane->panel = 'main';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bc08a14f-2055-4f39-96be-b7b11bf1a350';
    $display->content['new-bc08a14f-2055-4f39-96be-b7b11bf1a350'] = $pane;
    $display->panels['main'][0] = 'new-bc08a14f-2055-4f39-96be-b7b11bf1a350';
    $pane = new stdClass();
    $pane->pid = 'new-3efad32b-9378-4a85-9b73-f72db200416b';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_teaser';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3efad32b-9378-4a85-9b73-f72db200416b';
    $display->content['new-3efad32b-9378-4a85-9b73-f72db200416b'] = $pane;
    $display->panels['main'][1] = 'new-3efad32b-9378-4a85-9b73-f72db200416b';
    $pane = new stdClass();
    $pane->pid = 'new-123ae57a-9331-430a-b17a-dd4357ed337d';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'section_default_content-section_default_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '123ae57a-9331-430a-b17a-dd4357ed337d';
    $display->content['new-123ae57a-9331-430a-b17a-dd4357ed337d'] = $pane;
    $display->panels['main'][2] = 'new-123ae57a-9331-430a-b17a-dd4357ed337d';
    $pane = new stdClass();
    $pane->pid = 'new-689ce902-c98f-4f3e-8248-6ee5978d66a0';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'section_default_content-section_default_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '689ce902-c98f-4f3e-8248-6ee5978d66a0';
    $display->content['new-689ce902-c98f-4f3e-8248-6ee5978d66a0'] = $pane;
    $display->panels['main'][3] = 'new-689ce902-c98f-4f3e-8248-6ee5978d66a0';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:section:default:full'] = $panelizer;

  return $export;
}
