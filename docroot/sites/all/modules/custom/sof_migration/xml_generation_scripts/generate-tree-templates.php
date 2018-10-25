<?php

/**
 * @file
 * generate-tree-templates.php
 */

/**
 * Todo add comment for this function.
 */
function locate_xml_db() {
  return '/home/miro/Downloads/KKDK Export/all/ready/search-existing/locate-sitecore-xml.db';
}

/**
 * Todo add comment for this function.
 */
function locate_pages_xml_db() {
  return '/home/miro/Downloads/KKDK Export/all/ready/search-existing/locate-sitecore-pages-xml.db';
}

/**
 * Todo add comment for this function.
 */
function locate_blob_db() {
  return '/home/miro/Downloads/KKDK Export/all/ready/search-existing/locate-sitecore-blob.db';
}

/**
 * Todo add comment for this function.
 */
function generate_tree(array $rules) {
  $tree = array();
  $time = microtime(TRUE);
  $cwd = getcwd();

  // @codingStandardsIgnoreStart
  $Directory = new RecursiveDirectoryIterator($cwd);
  $Iterator = new RecursiveIteratorIterator($Directory);
  $Regex = new RegexIterator($Iterator, '#^.*{[^}]+}/da/1/xml$#', RecursiveRegexIterator::GET_MATCH);
  foreach ($Regex as $path_match) {
  // @codingStandardsIgnoreEnd
    find_matches($path_match[0], $tree, $rules);
  }

  // Save all output in files.
  tree_file_save_all($tree);

  $total_time = number_format(microtime(TRUE) - $time, 3, '.', '') . "\n";
  print "TOTAL TIME: $total_time\n";
  print "Done.\n";
}

/**
 * Todo add comment for this function.
 */
function generate_tree_from_single_template(array $rules, $template_path) {
  $tree = array();
  $time = microtime(TRUE);

  find_matches($template_path, $tree, $rules);

  // Save all output in files.
  tree_file_save_all($tree);

  $total_time = number_format(microtime(TRUE) - $time, 3, '.', '') . "\n";
  print "TOTAL TIME: $total_time\n";
  print "Done.\n";
}

/**
 * Todo add comment for this function.
 */
function tree_file_save_all($tree) {
  // Save final version of tree.
  tree_file_save_tree($tree);
  // Save final versions of guids files.
  guid_log_files_save();
  // Save final version of guid map file.
  map_files_save();
  // Save final version of XML package files.
  xml_package_files_save();
}

/**
 * Todo add comment for this function.
 */
function tree_file_save_tree($tree) {
  $cwd = getcwd();
  $output_file = 'templates-tree.php';
  $export = var_export($tree, TRUE);
  $export = "<?php\n\$export = $export;\n";
  file_put_contents("$cwd/$output_file", $export);
}

/**
 * Todo add comment for this function.
 */
function find_template_xml_file($template_id) {
  static $file_paths = array();
  $locate_db = locate_xml_db();

  if (!isset($file_paths[$template_id])) {
    $file_path = `locate -d "$locate_db" -n 1 "*/package/items/*/$template_id/da/1/xml"`;
    // Get first line, no line-break.
    list($file_path) = explode("\n", $file_path);
    $file_paths[$template_id] = $file_path;
  }

  return $file_paths[$template_id];
}

/**
 * Todo add comment for this function.
 */
function package_xml($package_key = NULL, $guid = NULL, $content = NULL) {
  static $packages = array();
  if (!$package_key) {
    ksort($packages);
    return $packages;
  }
  elseif ($content) {
    $packages[$package_key][$guid] = $content;
  }
  return FALSE;
}

/**
 * Todo add comment for this function.
 */
function xml_package_files_save() {
  $cwd = getcwd();
  foreach (package_xml() as $package_key => $contents) {
    $output_file = "$package_key-package.xml";
    $log = array();
    $xml_output = "<items>\n";
    foreach ($contents as $content) {
      $xml_output .= "$content\n";
    }
    $xml_output .= "</items>\n";
    file_put_contents("$cwd/$output_file", $xml_output);
  }
}

/**
 * Todo add comment for this function.
 */
function log_guid($log_key = NULL, $guid = NULL) {
  static $guids = array();
  if (!$log_key) {
    ksort($guids);
    foreach ($guids as $key => $val) {
      ksort($guids[$key]);
    }
    return $guids;
  }
  elseif ($guid) {
    $guids[$log_key][$guid] = $guid;
  }
  else {
    // Possibly handle some day.
  }
  return FALSE;
}

/**
 * Todo add comment for this function.
 */
function guid_log_files_save_txt() {
  $cwd = getcwd();
  foreach (log_guid() as $log_key => $guids) {
    $output_file = "$log_key-guids-string.txt";
    $all_guids_string = '';
    foreach ($guids as $guid) {
      $all_guids_string .= "$guid\n";
    }
    file_put_contents("$cwd/$output_file", $all_guids_string);
  }
}

/**
 * Todo add comment for this function.
 */
function guid_log_files_save() {
  $cwd = getcwd();
  foreach (log_guid() as $log_key => $guids) {
    $output_file = "$log_key-guids-log.php";
    $log = array();
    foreach ($guids as $guid) {
      $log[$guid] = $guid;
    }
    $export = var_export($log, TRUE);
    $export = "<?php\n\$export = $export;\n";
    file_put_contents("$cwd/$output_file", $export);
  }
}

/**
 * Todo add comment for this function.
 */
function intersect_get_from_file($filepath) {
  static $intersects = array();
  if (!isset($intersects[$filepath])) {
    require $filepath;
    $intersects[$filepath] = $export;
  }
  return $intersects[$filepath];
}

/**
 * Todo add comment for this function.
 */
function map_guid($map_key = NULL, $parent_id = NULL, $id = NULL) {
  static $map = array();
  if (!$map_key) {
    ksort($map);
    foreach ($map as $key => $val) {
      ksort($map[$key]);
    }
    return $map;
  }
  elseif ($id && $parent_id) {
    $map[$map_key][$parent_id][$id] = $id;
  }
  return FALSE;
}

/**
 * Todo add comment for this function.
 */
function map_custom($map_key = NULL, $set_key = NULL, $set_value = NULL) {
  static $map = array();
  if (!$map_key) {
    ksort($map);
    foreach ($map as $key => $val) {
      ksort($map[$key]);
    }
    return $map;
  }
  elseif ($set_key && $set_value) {
    $map[$map_key][$set_key] = $set_value;
  }
  return FALSE;
}

/**
 * Todo add comment for this function.
 */
function map_files_save() {
  $cwd = getcwd();
  // Duplication is good. I like duplication.
  foreach (map_guid() as $map_key => $map) {
    $output_file = "$map_key-guids-map.php";
    $export = var_export($map, TRUE);
    $export = "<?php\n\$export = $export;\n";
    file_put_contents("$cwd/$output_file", $export);
  }

  foreach (map_custom() as $map_key => $map) {
    $output_file = "$map_key-custom-map.php";
    $export = var_export($map, TRUE);
    $export = "<?php\n\$export = $export;\n";
    file_put_contents("$cwd/$output_file", $export);
  }
}

/**
 * Todo add comment for this function.
 */
function premapped_get_map($map_file) {
  static $maps = array();
  if (!isset($maps[$map_file])) {
    require $map_file;
    $maps[$map_file] = $export;
  }
  return $maps[$map_file];
}

/**
 * Todo add comment for this function.
 */
function find_matches($file_path, &$tree, $rules = array()) {
  $recurse_rules_callback = isset($rules['recurse_rules']) ? $rules['recurse_rules'] : 'find_matches_rules_default';
  $rules += $recurse_rules_callback();
  find_matches_recurse($file_path, $tree, $rules, 0);
}

/**
 * Todo add comment for this function.
 */
// @codingStandardsIgnoreStart
function find_matches_recurse($file_path, &$tree, $rules = array(), $depth) {
// @codingStandardsIgnoreEnd
  $file_contents = file_get_contents($file_path);
  if ($depth <= $rules['max_depth'] && $template = find_matches_template_match($file_contents, $rules)) {
    preg_match('#({[^}]+})/da/1/xml$#', $file_path, $guid_matches);
    $this_guid = $guid_matches[1];
    if (find_matches_template_intersect($this_guid, $file_contents, $rules)) {
      // Fill tree.
      if (isset($tree[$template])) {
        $tree[$template]['cnt']++;
      }
      else {
        $tree[$template] = array(
          'level' => $depth,
          'cnt' => 1,
          'children' => array(),
        );
      }

      // Package XML.
      if ($rules['package'] === '*' || in_array($template, $rules['package'])) {
        $log_key = isset($rules['package_key'][$template]) ? $rules['package_key'][$template] : $rules['package_key']['*'];
        $package_file_contents = $file_contents;
        foreach ($rules['package_preprocess'] as $callback) {
          $package_file_contents = $callback($file_path, $package_file_contents, $template, $rules);
        }
        package_xml($log_key, $this_guid, $package_file_contents);
      }

      // Log guid.
      find_matches_log_guid($this_guid, $template, $file_contents, $rules);

      // Log link from for example "Rich text" fields.
      find_matches_log_link($this_guid, $template, $file_contents, $rules);

      // Map guids.
      find_matches_map_guid($this_guid, $template, $file_contents, $rules);

      // Build custom maps.
      find_matches_map_custom($this_guid, $template, $file_contents, $rules);

      // Recurse children.
      find_matches_children($this_guid, $template, $file_contents, $tree, $rules, $depth);

      // Periodic save + print message.
      find_matches_progress($template, $tree, $rules);
    }
  }
}

/**
 * Todo add comment for this function.
 */
function find_matches_rules_default() {
  return array(
    'recurse' => TRUE,
    'recurse_rules' => __FUNCTION__,
    'max_depth' => 4,
    'match' => '*',
    'intersect' => array(),
    'package' => array(),
    'package_key' => array('*' => 'package-fallback'),
    'package_preprocess' => array(),
    'log_guid' => array(),
    'log_guid_key' => array('*' => 'guid-fallback'),
    'log_guid_filter' => array(),
    'log_link' => array(),
    'log_link_key' => array('*' => 'link-fallback'),
    'log_link_fetcher' => array(),
    'log_link_filter' => array(),
    'map_parent' => array(),
    'map_parent_key' => array('*' => 'map-fallback'),
    'map_children' => array(),
    'map_children_key' => array('*' => 'map-fallback'),
    'map_children_callback' => array(),
    'map_custom' => array(),
    'map_custom_key' => array('*' => 'map-fallback'),
    'map_custom_callback' => array(),
    'progress' => array(
      'interval' => 0,
      'message' => FALSE,
      'save' => FALSE,
    ),
    'children' => array('*' => array()),
    'children_premapped' => array(),
    'children_tree_list' => TRUE,
  );
}

/**
 * Todo add comment for this function.
 */
function find_matches_template_match($file_contents, array $rules) {
  $template_match = preg_match('/ template="([^"]+)"/', $file_contents, $template_matches);
  if ($template_match) {
    $template = $template_matches[1];
    if ($rules['match'] === '*' || in_array($template, $rules['match'])) {
      return $template;
    }
  }
}

/**
 * Todo add comment for this function.
 */
function find_matches_template_intersect($guid, $template, array $rules) {
  if ($rules['intersect']) {
    if ($rules['intersect'] === '*' || in_array($template, $rules['intersect'])) {
      $filepath = isset($rules['intersect_file'][$template]) ? $rules['intersect_file'][$template] : $rules['intersect_file']['*'];
      $intersect = intersect_get_from_file($filepath);
      return in_array($guid, $intersect);
    }
  }
  return TRUE;
}

/**
 * Todo add comment for this function.
 */
function find_matches_log_guid($this_guid, $template, $file_contents, array $rules) {
  if ($rules['log_guid'] === '*' || in_array($template, $rules['log_guid'])) {
    $log_guid = TRUE;
    foreach ($rules['log_guid_filter'] as $callback) {
      $result = $callback($this_guid, $template, $file_contents, $rules);
      if ($result === FALSE || $result === TRUE) {
        $log_guid = $result;
        break;
      }
    }
    if ($log_guid) {
      $log_key = isset($rules['log_guid_key'][$template]) ? $rules['log_guid_key'][$template] : $rules['log_guid_key']['*'];
      log_guid($log_key, $this_guid);
    }
  }
}

/**
 * Todo add comment for this function.
 */
function find_matches_log_link($this_guid, $template, $file_contents, array $rules) {
  preg_match_all('# key="([^"]+)" type="(Rich Text|Image|File|Link List|General Link)"><content>([^<]+)</content>#', $file_contents, $log_link_matches);
  foreach ($log_link_matches[1] as $match_key => $field_key) {
    if ($rules['log_link'] === '*' || in_array($field_key, $rules['log_link'])) {
      $field_type = $log_link_matches[2][$match_key];
      $field_content = $log_link_matches[3][$match_key];
      $guids = array();
      // Fetch links.
      foreach ($rules['log_link_fetcher'] as $callback) {
        foreach ($callback($field_key, $field_type, $field_content, $rules) as $guid) {
          $guids[$guid] = $guid;
        }
      }
      foreach ($guids as $guid) {
        $log_link = TRUE;
        // Filter link.
        foreach ($rules['log_link_filter'] as $callback) {
          $result = $callback($guid, $field_key, $file_contents, $rules);
          if ($result === FALSE || $result === TRUE) {
            $log_link = $result;
            break;
          }
        }
        if ($log_link) {
          // Log link.
          $log_key = isset($rules['log_link_key'][$field_key]) ? $rules['log_link_key'][$field_key] : $rules['log_link_key']['*'];
          log_guid($log_key, $guid);
        }
      }
    }
  }
}

/**
 * Todo add comment for this function.
 */
function find_matches_map_guid($this_guid, $template, $file_contents, array $rules) {
  // Map element to parent.
  if ($rules['map_parent'] === '*' || in_array($template, $rules['map_parent'])) {
    preg_match('/<item[^>]* parentid="({[^}]+})"[^>]*>/', $file_contents, $parent_matches);
    $map_key = isset($rules['map_parent_key'][$template]) ? $rules['map_parent_key'][$template] : $rules['map_parent_key']['*'];
    map_guid($map_key, $parent_matches[1], $this_guid);
  }

  // Map element to children.
  if ($rules['map_children'] === '*' || in_array($template, $rules['map_children'])) {
    $map_key = isset($rules['map_children_key'][$template]) ? $rules['map_children_key'][$template] : $rules['map_children_key']['*'];
    foreach ($rules['map_children_callback'] as $callback) {
      foreach ($callback($this_guid, $template, $file_contents) as $child_guid) {
        map_guid($map_key, $this_guid, $child_guid);
      }
    }
  }
}

/**
 * Todo add comment for this function.
 */
function find_matches_map_custom($this_guid, $template, $file_contents, array $rules) {
  if ($rules['map_custom'] === '*' || in_array($template, $rules['map_custom'])) {
    $map_key = isset($rules['map_custom_key'][$template]) ? $rules['map_custom_key'][$template] : $rules['map_custom_key']['*'];
    foreach ($rules['map_custom_callback'] as $callback) {
      foreach ($callback($this_guid, $template, $file_contents) as $set_key => $set_value) {
        map_custom($map_key, $set_key, $set_value);
      }
    }
  }
}

/**
 * Todo add comment for this function.
 */
function find_matches_children($this_guid, $template, $file_contents, array &$tree, array $rules, $depth) {

  if ($rules['recurse']) {
    $recurse_rules = isset($rules['children'][$template]) ? $rules['children'][$template] : $rules['children']['*'];
    $recurse_rules_callback = isset($rules['recurse_rules']) ? $rules['recurse_rules'] : 'find_matches_rules_default';
    $recurse_rules += $recurse_rules_callback();

    // Find premapped.
    if ($recurse_rules['children_premapped']) {
      foreach ($recurse_rules['children_premapped'] as $map_file) {
        $map = premapped_get_map($map_file);
        if (isset($map[$this_guid])) {
          foreach ($map[$this_guid] as $child_guid) {
            if ($subitem_file_path = find_template_xml_file($child_guid)) {
              find_matches_recurse($subitem_file_path, $tree[$template]['children'], $recurse_rules, ($depth + 1));
            }
          }
        }
      }
    }

    // Find in XML.
    if ($rules['children_tree_list']) {
      $fields_match = preg_match_all('# type="CustomTreeList"><content>({[^<]+})</content>#', $file_contents, $fields_matches);
      foreach ($fields_matches[1] as $children) {
        $children_match = preg_match_all('/{[^{}]+}/', $children, $children_matches);
        foreach ($children_matches[0] as $child_guid) {
          if ($subitem_file_path = find_template_xml_file($child_guid)) {
            // Get rules child search.
            find_matches_recurse($subitem_file_path, $tree[$template]['children'], $recurse_rules, ($depth + 1));
          }
        }
      }
    }
  }

  if (empty($tree[$template]['children'])) {
    // Remove empty array for clarity.
    unset($tree[$template]['children']);
  }
}

/**
 * Todo add comment for this function.
 */
function find_matches_progress($template, array &$tree, array $rules) {
  $progress = $rules['progress'];
  if ($progress['interval'] && $tree[$template]['cnt'] % $progress['interval'] === 0) {
    if ($progress['save']) {
      // Save all output in files.
      tree_file_save_all($tree);
    }
    if ($progress['message']) {
      print "Processed {$tree[$template]['cnt']} level {$tree[$template]['level']} '$template' items.\n";
    }
  }
}

/**
 * Helper functions.
 */

/**
 * Pass the guid, and optionally the template restriction.
 *
 * If found, returns an array with 3 arguments:
 * [
 *  - The file path of the file.
 *  - The XML file contents of the file.
 *  - The template the the file is.
 * ].
 */
function get_element($template_id, $match_template = NULL) {
  if ($file_path = find_template_xml_file($template_id)) {
    $file_contents = file_get_contents($file_path);
    if (preg_match('/ template="([^"]+)"/', $file_contents, $template_matches)) {
      if (!$match_template || $match_template === $template_matches[1]) {
        return array($file_contents, $file_path, $template_matches[1]);
      }
    }
  }
}

/**
 * Todo add comment for this function.
 */
function get_fields($file_contents, $field_key = NULL, $field_type = NULL) {
  foreach (array('field_key', 'field_type') as $argument) {
    if (is_null(${$argument})) {
      ${$argument} = '([^"]*)';
    }
    elseif (is_array(${$argument})) {
      ${$argument} = '(' . implode('|', ${$argument}) . ')';
    }
    else {
      ${$argument} = "({${$argument}})";
    }
  }

  preg_match_all("#<field(?: [^>]+)? key=\"$field_key\" type=\"$field_type\"><content>([^<]*)</content></field>#", $file_contents, $fields_matches);
  return $fields_matches;
}

/**
 * Todo add comment for this function.
 */
function doc_extra_node(DOMDocument $doc, DOMXPath $xpath = NULL, DOMNode $item = NULL) {
  if (!$xpath) {
    $xpath = new DOMXpath($doc);
  }
  if (!$item) {
    $item = $xpath->query('item', $doc)->item(0);
  }

  if ($item) {
    $extra = $xpath->query('extra', $item)->item(0);
    if (!$extra) {
      $extra = new DOMElement('extra');
      $item->appendChild($extra);
    }
    return $extra;
  }
}

/**
 * Todo add comment for this function.
 */
function get_query_array($query) {
  $result = array();
  if (!empty($query)) {
    foreach (explode('&', $query) as $param) {
      $param = explode('=', $param, 2);
      $result[$param[0]] = isset($param[1]) ? rawurldecode($param[1]) : '';
    }
  }
  return $result;
}

/**
 * Todo add comment for this function.
 */
function utf_ucfirst($text) {
  return mb_strtoupper(mb_substr($text, 0, 1)) . mb_substr($text, 1);
}

/**
 * Package_preprocess callbacks:.
 */

/**
 * Try to reduce the variety of urls that we have.
 *
 * So they are easier to match and handle.
 *
 * Currently rewrinting www.kk.dk.
 *
 * To make certain that linkchecker detects problematic links.
 *
 * Edit: decided not to rewrite urls, and to build a map insted.
 *
 * Which is much safer, and probably needed anyway.
 */
function rewrite_kkdk_urls($file_path, $file_contents, $template, array $rules) {
  // @codingStandardsIgnoreStart
  // $file_contents = preg_replace('# (src|href)=" *https?\://www\.kk\.dk([^"]*)"#', ' ${1}="http://kk.external.kk${2}"', $file_contents);
  //  $file_contents = preg_replace('# (src|href)=" *https?\://www\.kk\.dk([^"]*)"#', ' ${1}="http://www.kk.dk${2}"', $file_contents);.
  // @codingStandardsIgnoreEnd
  return $file_contents;
}

/**
 * Log_link_fetcher callbacks:.
 */
function get_links_by_type_richtext($field_key, $field_type, $field_content, array $rules) {
  $guids = array();

  if ($field_type === 'Rich Text') {
    preg_match_all('#="~/media/([^\.]+)\.ashx"#', $field_content, $link_matches);
    foreach ($link_matches[1] as $guid_no_dash) {
      $guid = preg_replace('/^(.{8})(.{4})(.{4})(.{4})(.*)$/', '{$1-$2-$3-$4-$5}', $guid_no_dash);
      $guids[$guid] = $guid;
    }
  }

  return $guids;
}

/**
 * Todo add comment for this function.
 */
function get_links_by_type_file($field_key, $field_type, $field_content, array $rules) {
  $guids = array();

  if ($field_type === 'Image' || $field_type === 'File') {
    // Match mediaid directly.
    preg_match_all('# mediaid="({[^}]+})"#', $field_content, $link_matches);
    foreach ($link_matches[1] as $guid) {
      $guids[$guid] = $guid;
    }
  }

  return $guids;
}

/**
 * Todo add comment for this function.
 */
function get_links_by_type_link($field_key, $field_type, $field_content, array $rules) {
  $guids = array();

  if ($field_type === 'Link List' || $field_type === 'General Link') {
    $doc = new DOMDocument();
    $docbody = '<body>' . html_entity_decode($field_content) . '</body>';
    @$doc->loadHTML($docbody);
    $xpath = new DOMXpath($doc);
    foreach ($xpath->query('//link', $doc) as $link) {
      $linktype = $link->getAttribute('linktype');
      $url = $link->getAttribute('url');
      $guid = $link->getAttribute('id');
      if ($linktype === 'media' && $url && $guid) {
        $guids[$guid] = $guid;
      }
    }
  }

  return $guids;
}
