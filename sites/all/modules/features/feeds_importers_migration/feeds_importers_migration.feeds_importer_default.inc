<?php
/**
 * @file
 * feeds_importers_migration.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function feeds_importers_migration_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'articles_importer';
  $feeds_importer->config = array(
    'name' => 'Articles importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => 0,
        'directory' => 'public://migrate',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => '@id',
          'xpathparser:4' => '@id',
          'xpathparser:1' => 'fields/field[@key="title"]/content',
          'xpathparser:2' => 'fields/field[@key="subheader"]/content',
          'xpathparser:3' => 'fields/field[@key="text"]/content',
          'xpathparser:5' => 'extra/old_url',
          'xpathparser:6' => 'fields/field[@key="__created"]/content',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:4' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
        ),
        'context' => '//items/item[extra/old_url[not(contains(.,\'/Aktuelt/\'))]]',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:4' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:4',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_teaser',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:3',
            'target' => 'body',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_old_url_article',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'created',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['articles_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'files';
  $feeds_importer->config = array(
    'name' => 'SOF Files',
    'description' => 'Import files for Skole og Forældre domain.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:3' => 'string(@id)',
          'xpathparser:1' => 'string(@id)',
          'xpathparser:2' => 'concat(string(@name), \'.\', fields/field[@key=\'extension\']/content/text())',
          'xpathparser:0' => 'fields/field[@key=\'blob\']/content/text()',
          'xpathparser:4' => '\'sof_migrated_files\'',
        ),
        'rawXML' => array(
          'xpathparser:3' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:0' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '/items/item',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:3' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:0' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'image',
        'author' => 0,
        'authorize' => 1,
        'copy_source' => 'public://sitecore',
        'copy_destination' => 'public://sof_migrated_files',
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'filename',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:0',
            'target' => 'copy',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_folder',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['files'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'fr_files';
  $feeds_importer->config = array(
    'name' => 'FR Files',
    'description' => 'Import files for Forældrerådgivningen domain.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:3' => 'string(@id)',
          'xpathparser:1' => 'string(@id)',
          'xpathparser:2' => 'concat(string(@name), \'.\', fields/field[@key=\'extension\']/content/text())',
          'xpathparser:0' => 'fields/field[@key=\'blob\']/content/text()',
          'xpathparser:4' => '\'fr_migrated_files\'',
        ),
        'rawXML' => array(
          'xpathparser:3' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:0' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '/items/item',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:3' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:0' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'image',
        'author' => 0,
        'authorize' => 1,
        'copy_source' => 'public://sitecore',
        'copy_destination' => 'public://fr_migrated_files',
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'filename',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:0',
            'target' => 'copy',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_folder',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['fr_files'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gidis_files';
  $feeds_importer->config = array(
    'name' => 'GIDIS Files',
    'description' => 'Import files for Good Id in Schools domain.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:3' => 'string(@id)',
          'xpathparser:1' => 'string(@id)',
          'xpathparser:2' => 'concat(string(@name), \'.\', fields/field[@key=\'extension\']/content/text())',
          'xpathparser:0' => 'fields/field[@key=\'blob\']/content/text()',
          'xpathparser:4' => '\'gidis_migrated_files\'',
        ),
        'rawXML' => array(
          'xpathparser:3' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:0' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '/items/item',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:3' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:0' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'image',
        'author' => 0,
        'authorize' => 1,
        'copy_source' => 'public://sitecore',
        'copy_destination' => 'public://gidis_migrated_files',
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'filename',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:0',
            'target' => 'copy',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_folder',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gidis_files'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'inkl_files';
  $feeds_importer->config = array(
    'name' => 'INKL Files',
    'description' => 'Import files for Inklusionsklar  domain.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:3' => 'string(@id)',
          'xpathparser:1' => 'string(@id)',
          'xpathparser:2' => 'concat(string(@name), \'.\', fields/field[@key=\'extension\']/content/text())',
          'xpathparser:0' => 'fields/field[@key=\'blob\']/content/text()',
          'xpathparser:4' => '\'inkl_migrated_files\'',
        ),
        'rawXML' => array(
          'xpathparser:3' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:0' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '/items/item',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:3' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:0' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'image',
        'author' => 0,
        'authorize' => 1,
        'copy_source' => 'public://sitecore',
        'copy_destination' => 'public://inkl_migrated_files',
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'filename',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:0',
            'target' => 'copy',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_folder',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['inkl_files'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'news_importer';
  $feeds_importer->config = array(
    'name' => 'News importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => 0,
        'directory' => 'public://migrate',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => '@id',
          'xpathparser:1' => 'fields/field[@key="title"]/content',
          'xpathparser:2' => 'fields/field[@key="subheader"]/content',
          'xpathparser:3' => 'fields/field[@key="text"]/content',
          'xpathparser:4' => '@id',
          'xpathparser:5' => 'extra/old_url',
          'xpathparser:6' => 'fields/field[@key="__created"]/content',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
        ),
        'context' => '//items/item[extra/old_url[contains(.,\'/Aktuelt/\')]]',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_teaser',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_old_url',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'created',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'news',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['news_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'noko_files';
  $feeds_importer->config = array(
    'name' => 'NOKO Files',
    'description' => 'Import files for Nordisk Komite domain.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:3' => 'string(@id)',
          'xpathparser:1' => 'string(@id)',
          'xpathparser:2' => 'concat(string(@name), \'.\', fields/field[@key=\'extension\']/content/text())',
          'xpathparser:0' => 'fields/field[@key=\'blob\']/content/text()',
          'xpathparser:4' => '\'noko_migrated_files\'',
        ),
        'rawXML' => array(
          'xpathparser:3' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:0' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '/items/item',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:3' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:0' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'image',
        'author' => 0,
        'authorize' => 1,
        'copy_source' => 'public://sitecore',
        'copy_destination' => 'public://noko_migrated_files',
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'filename',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:0',
            'target' => 'copy',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_folder',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['noko_files'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'sofkbh_files';
  $feeds_importer->config = array(
    'name' => 'SOFKBH Files',
    'description' => 'Import files for Skole og Forældre København domain.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:3' => 'string(@id)',
          'xpathparser:1' => 'string(@id)',
          'xpathparser:2' => 'concat(string(@name), \'.\', fields/field[@key=\'extension\']/content/text())',
          'xpathparser:0' => 'fields/field[@key=\'blob\']/content/text()',
          'xpathparser:4' => '\'sofkbh_migrated_files\'',
        ),
        'rawXML' => array(
          'xpathparser:3' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:0' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '/items/item',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:3' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:0' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'image',
        'author' => 0,
        'authorize' => 1,
        'copy_source' => 'public://sitecore',
        'copy_destination' => 'public://sofkbhH_migrated_files',
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'filename',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:0',
            'target' => 'copy',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_folder',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['sofkbh_files'] = $feeds_importer;

  return $export;
}
