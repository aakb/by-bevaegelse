<?php
/**
 * @file
 * bybevaeg_wysiwyg_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bybevaeg_wysiwyg_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: access ckeditor link.
  $permissions['access ckeditor link'] = array(
    'name' => 'access ckeditor link',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: administer ckeditor link.
  $permissions['administer ckeditor link'] = array(
    'name' => 'administer ckeditor link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: use text format editor_html.
  $permissions['use text format editor_html'] = array(
    'name' => 'use text format editor_html',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format video.
  $permissions['use text format video'] = array(
    'name' => 'use text format video',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
