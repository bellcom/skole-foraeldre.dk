<?php
/**
 * @file
 * sof_intro_deck_panel_pane.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sof_intro_deck_panel_pane_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_first_link_group|fieldable_panels_pane|intro_deck_pane|default';
  $field_group->group_name = 'group_first_link_group';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'intro_deck_pane';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = '';
  $export['group_first_link_group|fieldable_panels_pane|intro_deck_pane|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_first_link_group|fieldable_panels_pane|intro_deck_pane|form';
  $field_group->group_name = 'group_first_link_group';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'intro_deck_pane';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = '';
  $export['group_first_link_group|fieldable_panels_pane|intro_deck_pane|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_second_links_group|fieldable_panels_pane|intro_deck_pane|default';
  $field_group->group_name = 'group_second_links_group';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'intro_deck_pane';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = '';
  $export['group_second_links_group|fieldable_panels_pane|intro_deck_pane|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_second_links_group|fieldable_panels_pane|intro_deck_pane|form';
  $field_group->group_name = 'group_second_links_group';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'intro_deck_pane';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = '';
  $export['group_second_links_group|fieldable_panels_pane|intro_deck_pane|form'] = $field_group;

  return $export;
}
