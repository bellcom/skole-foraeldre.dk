<?php

/**
 * @file
 * sof_permissions_and_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function sof_permissions_and_roles_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 2,
  );

  // Exported role: site editor.
  $roles['site editor'] = array(
    'name' => 'site editor',
    'weight' => 3,
  );

  return $roles;
}
