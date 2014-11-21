<?php
/**
 * @file
 * sof_releases_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function sof_releases_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'releases';
  $page->task = 'page';
  $page->admin_title = 'Releases';
  $page->admin_description = 'Publication listing page';
  $page->path = 'releases/!query';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'query' => array(
      'id' => 1,
      'identifier' => 'Search query',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_releases_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'releases';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Releases';
  $display->uuid = 'd2e4ec03-0d57-4dcc-bb65-37df52aafbd1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0ea42ee1-7ce9-4572-a34e-065c21b83c2a';
    $pane->panel = 'one_main';
    $pane->type = 'apachesolr_form';
    $pane->subtype = 'apachesolr_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'path_type' => 'same',
      'path' => '',
      'override_prompt' => 1,
      'prompt' => '',
      'show_keys' => 1,
      'override_title' => 1,
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
    $pane->uuid = '0ea42ee1-7ce9-4572-a34e-065c21b83c2a';
    $display->content['new-0ea42ee1-7ce9-4572-a34e-065c21b83c2a'] = $pane;
    $display->panels['one_main'][0] = 'new-0ea42ee1-7ce9-4572-a34e-065c21b83c2a';
    $pane = new stdClass();
    $pane->pid = 'new-2296a5b7-0e46-48e9-95e6-52243aee424d';
    $pane->panel = 'one_main';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-afmHLrOrvV0J1iQ3M2ZHTioj00GibodG';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '2296a5b7-0e46-48e9-95e6-52243aee424d';
    $display->content['new-2296a5b7-0e46-48e9-95e6-52243aee424d'] = $pane;
    $display->panels['one_main'][1] = 'new-2296a5b7-0e46-48e9-95e6-52243aee424d';
    $pane = new stdClass();
    $pane->pid = 'new-71cfe0b2-298c-46c4-84a2-9f9cfc5c3a03';
    $pane->panel = 'one_main';
    $pane->type = 'views_panes';
    $pane->subtype = 'publication_listing_view-grid_listing_publication';
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
    $pane->uuid = '71cfe0b2-298c-46c4-84a2-9f9cfc5c3a03';
    $display->content['new-71cfe0b2-298c-46c4-84a2-9f9cfc5c3a03'] = $pane;
    $display->panels['one_main'][2] = 'new-71cfe0b2-298c-46c4-84a2-9f9cfc5c3a03';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['releases'] = $page;

  return $pages;

}