<?php

require 'generate-tree-templates.php';

$cwd = getcwd();

function rules_terms_tree_all() {
  $rules = array(
    'match' => '*',
    'package' => '*',
    'package_preprocess' => array(
      'article_build_url',
    ),
//    'map_parent_key' => array('*' => 'site-tree'),
    'progress' => array(
      'message' => TRUE,
      'save' => TRUE,
      'interval' => 200,
    ),
  );

  return $rules;
}


function article_build_url($file_path, $file_contents, $template, array $rules) {
  $cwd = getcwd();
  if ($template === 'artikel') {
    $doc = new DOMDocument();
    $doc->loadXML($file_contents);
    $xpath = new DOMXpath($doc);
    if ($item = $xpath->query('item', $doc)->item(0)) {
      if ($extra = doc_extra_node($doc, $xpath, $item)) {
        $sub_path = substr($file_path, strlen($cwd));
        if ($pos = stripos($sub_path, '/Ho')) {
          $sub_path = substr($sub_path, $pos + 1);
          $pos = stripos($sub_path, '{');
          $sub_path = substr($sub_path, 0, $pos - 1);
        }
        elseif ($pos = stripos($sub_path, '/Su')) {
          $sub_path = substr($sub_path, $pos + 1);
          $pos = stripos($sub_path, '{');
          $sub_path = substr($sub_path, 0, $pos - 1);
        }

        $pathele = new DOMElement('old_url', $sub_path);
        $extra->appendChild($pathele);
      }
      
      
      
      //        /master/sitecore/content/
      //        Home/OmOs/FormalVedtagter/{FFAC42F9-9EF7-4FC5-B818-7828CDA4D139}/da/1/xml
      
      
      
      
        //$extra = domelele $sub_path
        // $doc->domeappendchuld($extra)
        
//      if ($extra = doc_extra_node($doc, $xpath, $item)) {
//        //preg_match_all('#<field(?: [^>]+)? key="(?:contentspots|relatedspots|contentmodules)"[^>]*><content>({[a-zA-Z0-9\-\|{}]+})</content></field>#', $file_contents, $fields_matches);
//        //print_r($fields_matches);
//        exit('12');
//        $children = array();
//        foreach ($fields_matches[1] as $field_matches) {
//          $children = array_merge($children, explode('|', $field_matches));
//        }
//        foreach ($children as $child_guid) {
//          if ($get_element = get_element($child_guid, 'shortcutlinksspot')) {
//            list($child_contents) = $get_element;
//            $link_fields = get_fields($child_contents, 'navigationspotlinks');
//            if ($link_fields[2]) {
//              $navlinks = new DOMElement('navlinks', $link_fields[3][0]);
//              $extra->appendChild($navlinks);
//            }
//          }
//        }
//      }
      $file_contents = $doc->saveXML($item);
    }
  }

  return $file_contents;
}

$rules = rules_terms_tree_all();
generate_tree($rules);