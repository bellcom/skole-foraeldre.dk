<?php

/**
 * @file
 * Items XML Skole.
 *
 * @author Dobrin Dobrev <ddobrev@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

require 'generate-tree-templates.php';

$cwd = getcwd();

/**
 * Rule for terms tree all.
 */
function rules_terms_tree_all() {
  $rules = array(
    'match' => '*',
    'package' => '*',
    'package_preprocess' => array(
      'article_build_url',
    ),
    // 'map_parent_key' => array('*' => 'site-tree'),.
    'progress' => array(
      'message' => TRUE,
      'save' => TRUE,
      'interval' => 200,
    ),
  );

  return $rules;
}

/**
 * Article build URL.
 */
function article_build_url($file_path, $file_contents, $template, array $rules) {
  $cwd = getcwd();

  if ($template === 'artikel') {
    $doc = new DOMDocument();
    $doc->loadXML($file_contents);

    $xpath = new DOMXpath($doc);
    $item = $xpath->query('item', $doc)->item(0);
    if ($item) {
      $extra = doc_extra_node($doc, $xpath, $item);
      if ($extra) {
        $sub_path = substr($file_path, strlen($cwd));
        $pos = stripos($sub_path, '/Ho');
        if ($pos) {
          $sub_path = substr($sub_path, $pos + 1);
          $pos = stripos($sub_path, '{');
          $sub_path = substr($sub_path, 0, $pos - 1);
        }

        $pos = stripos($sub_path, '/Su');
        if ($pos) {
          $sub_path = substr($sub_path, $pos + 1);
          $pos = stripos($sub_path, '{');
          $sub_path = substr($sub_path, 0, $pos - 1);
        }

        $pathele = new DOMElement('old_url', $sub_path);
        $extra->appendChild($pathele);
      }

      // /master/sitecore/content/
      // Home/OmOs/FormalVedtagter/{FFAC42F9-9EF7-4FC5-B818-7828CDA4D139}/da/1/xml.
      $file_contents = $doc->saveXML($item);
    }
  }

  return $file_contents;
}

$rules = rules_terms_tree_all();
generate_tree($rules);
