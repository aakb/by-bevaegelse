<?php
/**
 * @file
 * bybevaeg_pages_overrides.features.inc
 */

/**
 * Implements hook_field_default_fields_alter().
 */
function bybevaeg_pages_overrides_field_default_fields_alter(&$data) {
  if (isset($data['node-static_page-field_content'])) {
    $data['node-static_page-field_content']['field_instance']['required'] = 0; /* WAS: 1 */
  }
}
