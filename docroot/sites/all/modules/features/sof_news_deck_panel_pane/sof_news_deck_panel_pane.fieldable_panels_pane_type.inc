<?php
/**
 * @file
 * sof_news_deck_panel_pane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function sof_news_deck_panel_pane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'news_pane';
  $fieldable_panels_pane_type->title = 'News deck';
  $fieldable_panels_pane_type->description = 'Adds one highlighted news/article editor picked node at the top. In addition there will be 3 latest news/articles, social media links and also external link picked by the editor.';
  $export['news_pane'] = $fieldable_panels_pane_type;

  return $export;
}
