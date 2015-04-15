<?php
/**
 * @file
 * sof_home_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function sof_home_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = 'SOF home page';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home-page-panel',
    'css_id' => 'home-page-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93df7b9d-0494-4234-b07f-a7d0fb88500d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c2199909-198d-4514-9d88-085368e72cb8';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:16172dc7-28fa-4dce-a6ab-da7a62a224e9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c2199909-198d-4514-9d88-085368e72cb8';
    $display->content['new-c2199909-198d-4514-9d88-085368e72cb8'] = $pane;
    $display->panels['main'][0] = 'new-c2199909-198d-4514-9d88-085368e72cb8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel_context_eaf885d3-c0e3-4be5-95e2-d1ca673ac27b';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Skole og Forældre',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home-page-panel',
    'css_id' => 'home-page-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'domain',
          'settings' => array(
            'domain_site' => 0,
            'domains' => array(
              'www_sof_prelive_workingpropeople_com' => 'www_sof_prelive_workingpropeople_com',
              'www_fr_prelive_workingpropeople_com' => 0,
              'www_sofkbh_prelive_workingpropeople_com' => 0,
              'www_noko_prelive_workingpropeople_com' => 0,
              'www_gidis_prelive_workingpropeople_com' => 0,
              'www_inkl_prelive_workingpropeople_com' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93df7b9d-0494-4234-b07f-a7d0fb88500d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-89ade5a0-b8ff-4016-bb9d-17fb32cc6c3d';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:f1ace9c8-6a7c-4a87-95c7-b74f2093632b';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '89ade5a0-b8ff-4016-bb9d-17fb32cc6c3d';
    $display->content['new-89ade5a0-b8ff-4016-bb9d-17fb32cc6c3d'] = $pane;
    $display->panels['main'][0] = 'new-89ade5a0-b8ff-4016-bb9d-17fb32cc6c3d';
    $pane = new stdClass();
    $pane->pid = 'new-6e42367e-383e-4b3d-93ed-842902d92acf';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:90073625-b432-4ce4-9227-6af35ba894a1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6e42367e-383e-4b3d-93ed-842902d92acf';
    $display->content['new-6e42367e-383e-4b3d-93ed-842902d92acf'] = $pane;
    $display->panels['main'][1] = 'new-6e42367e-383e-4b3d-93ed-842902d92acf';
    $pane = new stdClass();
    $pane->pid = 'new-68382848-aeb8-4b69-bbbf-8de1a2a19eeb';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:1109587e-b9c6-4c94-9aed-f84dc78baefc';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '68382848-aeb8-4b69-bbbf-8de1a2a19eeb';
    $display->content['new-68382848-aeb8-4b69-bbbf-8de1a2a19eeb'] = $pane;
    $display->panels['main'][2] = 'new-68382848-aeb8-4b69-bbbf-8de1a2a19eeb';
    $pane = new stdClass();
    $pane->pid = 'new-67253b93-75d8-41f5-bab3-25514656010a';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:db1c552e-d320-473a-aaea-ab4bdf8f8040';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '67253b93-75d8-41f5-bab3-25514656010a';
    $display->content['new-67253b93-75d8-41f5-bab3-25514656010a'] = $pane;
    $display->panels['main'][3] = 'new-67253b93-75d8-41f5-bab3-25514656010a';
    $pane = new stdClass();
    $pane->pid = 'new-9012eb09-0c64-4f87-91ed-f3f19492add0';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:eecf8b23-7d94-48ac-bc42-ecacfeabc9c3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '9012eb09-0c64-4f87-91ed-f3f19492add0';
    $display->content['new-9012eb09-0c64-4f87-91ed-f3f19492add0'] = $pane;
    $display->panels['main'][4] = 'new-9012eb09-0c64-4f87-91ed-f3f19492add0';
    $pane = new stdClass();
    $pane->pid = 'new-d7b39b76-f11c-40e5-b15e-29c6f9baff3f';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:cfbbf59b-34f8-4f5e-9683-dcfad0a56d92';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'd7b39b76-f11c-40e5-b15e-29c6f9baff3f';
    $display->content['new-d7b39b76-f11c-40e5-b15e-29c6f9baff3f'] = $pane;
    $display->panels['main'][5] = 'new-d7b39b76-f11c-40e5-b15e-29c6f9baff3f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel_context_6598e3d6-d603-409d-a23d-fa9133e5f874';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'FR',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home-page-panel',
    'css_id' => 'home-page-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'domain',
          'settings' => array(
            'domain_site' => 0,
            'domains' => array(
              'www_fr_prelive_workingpropeople_com' => 'www_fr_prelive_workingpropeople_com',
              'www_sof_prelive_workingpropeople_com' => 0,
              'www_sofkbh_prelive_workingpropeople_com' => 0,
              'www_noko_prelive_workingpropeople_com' => 0,
              'www_gidis_prelive_workingpropeople_com' => 0,
              'www_inkl_prelive_workingpropeople_com' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93df7b9d-0494-4234-b07f-a7d0fb88500d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2a727a2c-196c-42a6-8f02-61a6e99f99b7';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:d5c4e854-83c6-487f-ac28-bcdd2ab15203';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2a727a2c-196c-42a6-8f02-61a6e99f99b7';
    $display->content['new-2a727a2c-196c-42a6-8f02-61a6e99f99b7'] = $pane;
    $display->panels['main'][0] = 'new-2a727a2c-196c-42a6-8f02-61a6e99f99b7';
    $pane = new stdClass();
    $pane->pid = 'new-57d1ce3c-5f5d-466c-b01c-e6b5b74cbf47';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:5e71f09c-1b0d-4fd1-a460-f1974ea1b8f9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '57d1ce3c-5f5d-466c-b01c-e6b5b74cbf47';
    $display->content['new-57d1ce3c-5f5d-466c-b01c-e6b5b74cbf47'] = $pane;
    $display->panels['main'][1] = 'new-57d1ce3c-5f5d-466c-b01c-e6b5b74cbf47';
    $pane = new stdClass();
    $pane->pid = 'new-bc9776d7-fff0-4645-9e40-6f86b35c495a';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:26440573-f43d-44ff-94d7-97023c84579a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bc9776d7-fff0-4645-9e40-6f86b35c495a';
    $display->content['new-bc9776d7-fff0-4645-9e40-6f86b35c495a'] = $pane;
    $display->panels['main'][2] = 'new-bc9776d7-fff0-4645-9e40-6f86b35c495a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel_context_79199b71-dbfe-4e12-8343-593d93ea8b51';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'SOFKBH',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home-page-panel',
    'css_id' => 'home-page-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'domain',
          'settings' => array(
            'domain_site' => 0,
            'domains' => array(
              'www_sofkbh_prelive_workingpropeople_com' => 'www_sofkbh_prelive_workingpropeople_com',
              'www_sof_prelive_workingpropeople_com' => 0,
              'www_fr_prelive_workingpropeople_com' => 0,
              'www_noko_prelive_workingpropeople_com' => 0,
              'www_gidis_prelive_workingpropeople_com' => 0,
              'www_inkl_prelive_workingpropeople_com' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93df7b9d-0494-4234-b07f-a7d0fb88500d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7cf22389-20f3-49aa-9f7b-6f421cf4c5cd';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:a099b807-94ae-422b-8648-fb9ea99e92dd';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7cf22389-20f3-49aa-9f7b-6f421cf4c5cd';
    $display->content['new-7cf22389-20f3-49aa-9f7b-6f421cf4c5cd'] = $pane;
    $display->panels['main'][0] = 'new-7cf22389-20f3-49aa-9f7b-6f421cf4c5cd';
    $pane = new stdClass();
    $pane->pid = 'new-3a7675ed-eaaf-4840-a59e-cc59842119c9';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:0a51aa19-fc1b-40db-9501-f2d453fbe492';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3a7675ed-eaaf-4840-a59e-cc59842119c9';
    $display->content['new-3a7675ed-eaaf-4840-a59e-cc59842119c9'] = $pane;
    $display->panels['main'][1] = 'new-3a7675ed-eaaf-4840-a59e-cc59842119c9';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel_context_c0fa3e91-b9c4-434e-b481-b1ee53e4a186';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'NOKO',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home-page-panel',
    'css_id' => 'home-page-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'domain',
          'settings' => array(
            'domain_site' => 0,
            'domains' => array(
              'www_noko_prelive_workingpropeople_com' => 'www_noko_prelive_workingpropeople_com',
              'www_sof_prelive_workingpropeople_com' => 0,
              'www_fr_prelive_workingpropeople_com' => 0,
              'www_sofkbh_prelive_workingpropeople_com' => 0,
              'www_gidis_prelive_workingpropeople_com' => 0,
              'www_inkl_prelive_workingpropeople_com' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93df7b9d-0494-4234-b07f-a7d0fb88500d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ba6a2990-c9f6-4222-887d-7b9bca989555';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:dec6c084-fb51-42eb-a884-b88eae9a7327';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ba6a2990-c9f6-4222-887d-7b9bca989555';
    $display->content['new-ba6a2990-c9f6-4222-887d-7b9bca989555'] = $pane;
    $display->panels['main'][0] = 'new-ba6a2990-c9f6-4222-887d-7b9bca989555';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel_context_a43c7876-61b2-4ebb-9b90-b0171df08bfd';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'GIDIS',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home-page-panel',
    'css_id' => 'home-page-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'domain',
          'settings' => array(
            'domain_site' => 0,
            'domains' => array(
              'www_gidis_prelive_workingpropeople_com' => 'www_gidis_prelive_workingpropeople_com',
              'www_sof_prelive_workingpropeople_com' => 0,
              'www_fr_prelive_workingpropeople_com' => 0,
              'www_sofkbh_prelive_workingpropeople_com' => 0,
              'www_noko_prelive_workingpropeople_com' => 0,
              'www_inkl_prelive_workingpropeople_com' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93df7b9d-0494-4234-b07f-a7d0fb88500d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d32c5434-769a-4a3a-9ece-1bba3f20cca5';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:edd0b640-5bbf-49d6-b658-2e4b29c7114d';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd32c5434-769a-4a3a-9ece-1bba3f20cca5';
    $display->content['new-d32c5434-769a-4a3a-9ece-1bba3f20cca5'] = $pane;
    $display->panels['main'][0] = 'new-d32c5434-769a-4a3a-9ece-1bba3f20cca5';
    $pane = new stdClass();
    $pane->pid = 'new-72360ee3-7dd3-4613-880b-fea70e692935';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:1554d59c-a382-4085-92ba-95c4f1117f8c';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '72360ee3-7dd3-4613-880b-fea70e692935';
    $display->content['new-72360ee3-7dd3-4613-880b-fea70e692935'] = $pane;
    $display->panels['main'][1] = 'new-72360ee3-7dd3-4613-880b-fea70e692935';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel_context_c3ea3d7d-88aa-480f-98ad-53cc30553328';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'INKL',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home-page-panel',
    'css_id' => 'home-page-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'domain',
          'settings' => array(
            'domain_site' => 0,
            'domains' => array(
              'www_inkl_prelive_workingpropeople_com' => 'www_inkl_prelive_workingpropeople_com',
              'www_sof_prelive_workingpropeople_com' => 0,
              'www_fr_prelive_workingpropeople_com' => 0,
              'www_sofkbh_prelive_workingpropeople_com' => 0,
              'www_noko_prelive_workingpropeople_com' => 0,
              'www_gidis_prelive_workingpropeople_com' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93df7b9d-0494-4234-b07f-a7d0fb88500d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-41310420-3d0a-4743-b6c5-04c0a4e0d6f8';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:3f5dc4d5-353b-42d3-bcda-6d47b0cef2f6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '41310420-3d0a-4743-b6c5-04c0a4e0d6f8';
    $display->content['new-41310420-3d0a-4743-b6c5-04c0a4e0d6f8'] = $pane;
    $display->panels['main'][0] = 'new-41310420-3d0a-4743-b6c5-04c0a4e0d6f8';
    $pane = new stdClass();
    $pane->pid = 'new-3de51900-0704-4ae1-bd88-f8f3f4dc5614';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:22be2df5-2aeb-4fce-acb8-e63a10c3d75c';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3de51900-0704-4ae1-bd88-f8f3f4dc5614';
    $display->content['new-3de51900-0704-4ae1-bd88-f8f3f4dc5614'] = $pane;
    $display->panels['main'][1] = 'new-3de51900-0704-4ae1-bd88-f8f3f4dc5614';
    $pane = new stdClass();
    $pane->pid = 'new-ae6c9dbe-4139-4c04-b24e-ecb3ccce2fac';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:102f3502-b1b8-47fb-989a-43110d8625a5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ae6c9dbe-4139-4c04-b24e-ecb3ccce2fac';
    $display->content['new-ae6c9dbe-4139-4c04-b24e-ecb3ccce2fac'] = $pane;
    $display->panels['main'][2] = 'new-ae6c9dbe-4139-4c04-b24e-ecb3ccce2fac';
    $pane = new stdClass();
    $pane->pid = 'new-2ace4089-78e1-47ee-ae7e-b8ffb12c574c';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:7dbfe69d-4204-42f1-aa9e-86a05bf67956';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2ace4089-78e1-47ee-ae7e-b8ffb12c574c';
    $display->content['new-2ace4089-78e1-47ee-ae7e-b8ffb12c574c'] = $pane;
    $display->panels['main'][3] = 'new-2ace4089-78e1-47ee-ae7e-b8ffb12c574c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__default';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'home-page-panel',
    'css_id' => 'home-page-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'default',
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f13c0446-0900-4496-8f5d-8280a41a028f';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
