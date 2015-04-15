<?php
/**
 * @file
 * sof_apache_solr_configuration.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function sof_apache_solr_configuration_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'search_results';
  $item->label = 'Søgeresultat';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Din søgning på <em>"[facetapi_results:keys]"</em> gav [facetapi_results:result-count] resultater.',
        'plural' => 1,
        'text_plural' => 'Din søgning på <em>"[facetapi_results:keys]"</em> gav [facetapi_results:result-count] resultater.',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h2',
        'css' => 0,
        'classes' => '',
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '0',
    ),
  );
  $export['search_results'] = $item;

  return $export;
}
