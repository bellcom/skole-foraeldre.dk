<?php
/**
 * @file
 * sof_question_and_answers.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function sof_question_and_answers_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'qna_page';
  $page->task = 'page';
  $page->admin_title = 'QnA Page';
  $page->admin_description = 'This is the page, containing Questions and Answers';
  $page->path = 'qa';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_qna_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'qna_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
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
  $display->title = 'Spørgsmål og svar';
  $display->uuid = 'fd5280fd-7a65-4493-8311-bf60cb3acaad';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_qna_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d2d91854-b4d7-49e7-8173-2b2884af8bef';
  $pane->panel = 'one_main';
  $pane->type = 'block';
  $pane->subtype = 'sof_qa_search-sof_qa_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd2d91854-b4d7-49e7-8173-2b2884af8bef';
  $display->content['new-d2d91854-b4d7-49e7-8173-2b2884af8bef'] = $pane;
  $display->panels['one_main'][0] = 'new-d2d91854-b4d7-49e7-8173-2b2884af8bef';
  $pane = new stdClass();
  $pane->pid = 'new-e49d4ee3-8ae4-46dd-9c37-28d74c850e19';
  $pane->panel = 'one_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'qa_taxonomy_view-taxonomy_view_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e49d4ee3-8ae4-46dd-9c37-28d74c850e19';
  $display->content['new-e49d4ee3-8ae4-46dd-9c37-28d74c850e19'] = $pane;
  $display->panels['one_main'][1] = 'new-e49d4ee3-8ae4-46dd-9c37-28d74c850e19';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['qna_page'] = $page;

  return $pages;

}
