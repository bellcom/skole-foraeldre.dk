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
  $handler->weight = -23;
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_panel_context';
  $display->content = array();
  $display->panels = array();
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__panel_context_eaf885d3-c0e3-4be5-95e2-d1ca673ac27b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f0d10ddd-9fa8-4473-bd13-4a5914f3b85c';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:238';
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
  $pane->uuid = 'f0d10ddd-9fa8-4473-bd13-4a5914f3b85c';
  $display->content['new-f0d10ddd-9fa8-4473-bd13-4a5914f3b85c'] = $pane;
  $display->panels['main'][0] = 'new-f0d10ddd-9fa8-4473-bd13-4a5914f3b85c';
  $pane = new stdClass();
  $pane->pid = 'new-1be775bb-4022-48dc-a352-37d06ad59f99';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:ba133d78-cff3-45d0-8168-c84f537790df';
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
  $pane->uuid = '1be775bb-4022-48dc-a352-37d06ad59f99';
  $display->content['new-1be775bb-4022-48dc-a352-37d06ad59f99'] = $pane;
  $display->panels['main'][1] = 'new-1be775bb-4022-48dc-a352-37d06ad59f99';
  $pane = new stdClass();
  $pane->pid = 'new-68382848-aeb8-4b69-bbbf-8de1a2a19eeb';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:164';
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
  $pane->subtype = 'current:135';
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
  $pane->subtype = 'current:136';
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
  $pane->subtype = 'current:157';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__panel_context_6598e3d6-d603-409d-a23d-fa9133e5f874';
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
  $pane->pid = 'new-aa55bad4-3d7e-4c4f-88b0-b688e1f0488a';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:333';
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
  $pane->uuid = 'aa55bad4-3d7e-4c4f-88b0-b688e1f0488a';
  $display->content['new-aa55bad4-3d7e-4c4f-88b0-b688e1f0488a'] = $pane;
  $display->panels['main'][1] = 'new-aa55bad4-3d7e-4c4f-88b0-b688e1f0488a';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '57d1ce3c-5f5d-466c-b01c-e6b5b74cbf47';
  $display->content['new-57d1ce3c-5f5d-466c-b01c-e6b5b74cbf47'] = $pane;
  $display->panels['main'][2] = 'new-57d1ce3c-5f5d-466c-b01c-e6b5b74cbf47';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'bc9776d7-fff0-4645-9e40-6f86b35c495a';
  $display->content['new-bc9776d7-fff0-4645-9e40-6f86b35c495a'] = $pane;
  $display->panels['main'][3] = 'new-bc9776d7-fff0-4645-9e40-6f86b35c495a';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__panel_context_79199b71-dbfe-4e12-8343-593d93ea8b51';
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
  $pane = new stdClass();
  $pane->pid = 'new-16edf766-6177-44b6-bea1-de30962a86a1';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:207';
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
  $pane->uuid = '16edf766-6177-44b6-bea1-de30962a86a1';
  $display->content['new-16edf766-6177-44b6-bea1-de30962a86a1'] = $pane;
  $display->panels['main'][2] = 'new-16edf766-6177-44b6-bea1-de30962a86a1';
  $pane = new stdClass();
  $pane->pid = 'new-08ad08a8-6b74-4334-9c1b-3c56e98c6ec5';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:926796ca-d751-4ad2-8710-d53ae5fd0ed3';
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
  $pane->uuid = '08ad08a8-6b74-4334-9c1b-3c56e98c6ec5';
  $display->content['new-08ad08a8-6b74-4334-9c1b-3c56e98c6ec5'] = $pane;
  $display->panels['main'][3] = 'new-08ad08a8-6b74-4334-9c1b-3c56e98c6ec5';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__panel_context_c0fa3e91-b9c4-434e-b481-b1ee53e4a186';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__panel_context_a43c7876-61b2-4ebb-9b90-b0171df08bfd';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__panel_context_c3ea3d7d-88aa-480f-98ad-53cc30553328';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4dc6f15a-f5a3-4b70-bfd7-d9b19ac32098';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:76e6e638-c71c-444b-a4f6-8e95c88ae245';
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
  $pane->uuid = '4dc6f15a-f5a3-4b70-bfd7-d9b19ac32098';
  $display->content['new-4dc6f15a-f5a3-4b70-bfd7-d9b19ac32098'] = $pane;
  $display->panels['main'][0] = 'new-4dc6f15a-f5a3-4b70-bfd7-d9b19ac32098';
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
  $pane = new stdClass();
  $pane->pid = 'new-dde8d3d0-ccc7-4135-af77-c967ca358ba9';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:200';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'dde8d3d0-ccc7-4135-af77-c967ca358ba9';
  $display->content['new-dde8d3d0-ccc7-4135-af77-c967ca358ba9'] = $pane;
  $display->panels['main'][4] = 'new-dde8d3d0-ccc7-4135-af77-c967ca358ba9';
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
  $handler->weight = -22;
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__default';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__dmskole';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'DMSKOLE',
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
              'www_dmskoleudvikling_dk' => 'www_dmskoleudvikling_dk',
              'www_sof_prelive_workingpropeople_com' => 0,
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
    'name' => 'dmskole',
  );
  $display = new panels_display();
  $display->layout = 'sof-one-column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
    'main' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '93df7b9d-0494-4234-b07f-a7d0fb88500d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__dmskole';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5d5c3f53-08df-41f9-ab31-03abb0468d11';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:b8ce5f96-3e40-4a48-8cc4-a4cd1a8b4e79';
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
  $pane->uuid = '5d5c3f53-08df-41f9-ab31-03abb0468d11';
  $display->content['new-5d5c3f53-08df-41f9-ab31-03abb0468d11'] = $pane;
  $display->panels['main'][0] = 'new-5d5c3f53-08df-41f9-ab31-03abb0468d11';
  $pane = new stdClass();
  $pane->pid = 'new-e1db84f0-f3c2-418e-bc83-1c50c4495bc7';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:256';
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
  $pane->uuid = 'e1db84f0-f3c2-418e-bc83-1c50c4495bc7';
  $display->content['new-e1db84f0-f3c2-418e-bc83-1c50c4495bc7'] = $pane;
  $display->panels['main'][1] = 'new-e1db84f0-f3c2-418e-bc83-1c50c4495bc7';
  $pane = new stdClass();
  $pane->pid = 'new-4c7d82d5-448d-4daf-9baa-9353e35ca41d';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:257';
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
  $pane->uuid = '4c7d82d5-448d-4daf-9baa-9353e35ca41d';
  $display->content['new-4c7d82d5-448d-4daf-9baa-9353e35ca41d'] = $pane;
  $display->panels['main'][2] = 'new-4c7d82d5-448d-4daf-9baa-9353e35ca41d';
  $pane = new stdClass();
  $pane->pid = 'new-e9fb8cdb-5372-454a-ac7c-2c1e062dadf2';
  $pane->panel = 'main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:282';
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
  $pane->uuid = 'e9fb8cdb-5372-454a-ac7c-2c1e062dadf2';
  $display->content['new-e9fb8cdb-5372-454a-ac7c-2c1e062dadf2'] = $pane;
  $display->panels['main'][3] = 'new-e9fb8cdb-5372-454a-ac7c-2c1e062dadf2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
