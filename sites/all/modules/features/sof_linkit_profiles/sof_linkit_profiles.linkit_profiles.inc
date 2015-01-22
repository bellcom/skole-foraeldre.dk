<?php
/**
 * @file
 * sof_linkit_profiles.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function sof_linkit_profiles_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'sof_banner_deck_links';
  $linkit_profile->admin_title = 'SOF Banner deck links';
  $linkit_profile->admin_description = 'Links for banner deck';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:bean' => array(
      'result_description' => '',
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_article' => 0,
        'comment_node_basic_page' => 0,
        'comment_node_news' => 0,
        'comment_node_publication' => 0,
        'comment_node_section' => 0,
        'comment_node_slider' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:node' => array(
      'result_description' => '[node:title] [[node:type] - nid: [node:nid]]',
      'bundles' => array(
        'article' => 'article',
        'basic_page' => 'basic_page',
        'news' => 'news',
        'publication' => 'publication',
        'section' => 'section',
        'webform' => 'webform',
        'slider' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 0,
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'media_folders' => 0,
        'general_category' => 0,
        'publication_category' => 0,
        'tags' => 0,
        'magazine_categories' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'plugin' => 'raw_url',
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['sof_banner_deck_links'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'sof_recommended_items';
  $linkit_profile->admin_title = 'SOF Recommended items';
  $linkit_profile->admin_description = 'HTML links to different nodes';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:bean' => array(
      'result_description' => '',
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_article' => 0,
        'comment_node_basic_page' => 0,
        'comment_node_news' => 0,
        'comment_node_publication' => 0,
        'comment_node_section' => 0,
        'comment_node_slider' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:node' => array(
      'result_description' => '[node:title] [[node:type] - nid: [node:nid]]',
      'bundles' => array(
        'article' => 'article',
        'basic_page' => 'basic_page',
        'news' => 'news',
        'publication' => 'publication',
        'section' => 'section',
        'webform' => 'webform',
        'slider' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 0,
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'media_folders' => 0,
        'general_category' => 0,
        'publication_category' => 0,
        'tags' => 0,
        'magazine_categories' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'plugin' => 'raw_url',
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['sof_recommended_items'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'sof_wysiwyg';
  $linkit_profile->admin_title = 'SOF Wysiwyg';
  $linkit_profile->admin_description = 'Insert links to different type of content in the editors.';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'full_html' => 'full_html',
      'plain_text' => 0,
      'commerce_order_message' => 0,
    ),
    'search_plugins' => array(
      'entity:commerce_product' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:commerce_payment_transaction' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'sof_pdf_generator' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:bean' => array(
      'result_description' => '',
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_article' => 0,
        'comment_node_basic_page' => 0,
        'comment_node_news' => 0,
        'comment_node_publication' => 0,
        'comment_node_section' => 0,
        'comment_node_slider' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:commerce_payment_transaction' => array(
      'result_description' => '',
    ),
    'entity:commerce_product' => array(
      'result_description' => '',
    ),
    'entity:node' => array(
      'result_description' => '[node:title] [[node:type] - nid: [node:nid]]',
      'bundles' => array(
        'article' => 'article',
        'basic_page' => 'basic_page',
        'news' => 'news',
        'publication' => 'publication',
        'section' => 'section',
        'webform' => 'webform',
        'slider' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 0,
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'media_folders' => 0,
        'general_category' => 0,
        'magazine_categories' => 0,
        'publication_category' => 0,
        'tags' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'sof_pdf_generator' => array(
      'result_description' => '[node:title] [nid: [node:nid]]',
      'include_unpublished' => 0,
    ),
    'insert_plugin' => array(
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['sof_wysiwyg'] = $linkit_profile;

  return $export;
}
