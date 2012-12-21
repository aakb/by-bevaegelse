<?php
/**
 * @file
 * bybevaeg_pages_overrides.features.inc
 */

/**
 * Implements hook_field_default_fields_alter().
 */
function bybevaeg_pages_overrides_field_default_fields_alter(&$data) {
  if (isset($data['node-static_page-field_download'])) {
    $data['node-static_page-field_download']['field_instance']['display']['default']['type'] = 'hidden'; /* WAS: 'file_default' */
    $data['node-static_page-field_download']['field_instance']['display']['default']['weight'] = '3'; /* WAS: '4' */
    unset($data['node-static_page-field_download']['field_instance']['display']['default']['module']);
  }
  if (isset($data['node-static_page-field_links'])) {
    $data['node-static_page-field_links']['field_instance']['display']['default']['type'] = 'hidden'; /* WAS: 'link_default' */
    $data['node-static_page-field_links']['field_instance']['display']['default']['weight'] = '2'; /* WAS: '3' */
    unset($data['node-static_page-field_links']['field_instance']['display']['default']['module']);
  }
  if (isset($data['node-static_page-field_spotbox_title'])) {
    $data['node-static_page-field_spotbox_title']['field_instance']['display']['default']['type'] = 'hidden'; /* WAS: 'text_default' */
    $data['node-static_page-field_spotbox_title']['field_instance']['display']['default']['weight'] = '6'; /* WAS: '4' */
    unset($data['node-static_page-field_spotbox_title']['field_instance']['display']['default']['module']);
  }
  if (isset($data['node-static_page-field_subject'])) {
    $data['node-static_page-field_subject']['field_instance']['display']['default']['type'] = 'hidden'; /* WAS: 'taxonomy_term_reference_link' */
    $data['node-static_page-field_subject']['field_instance']['display']['default']['weight'] = '4'; /* WAS: 5 */
    unset($data['node-static_page-field_subject']['field_instance']['display']['default']['module']);
  }
  if (isset($data['node-static_page-field_tags'])) {
    $data['node-static_page-field_tags']['field_instance']['display']['default']['type'] = 'hidden'; /* WAS: 'taxonomy_term_reference_link' */
    $data['node-static_page-field_tags']['field_instance']['display']['default']['weight'] = '5'; /* WAS: 6 */
    unset($data['node-static_page-field_tags']['field_instance']['display']['default']['module']);
  }
}

/**
 * Implements hook_image_styles_alter().
 */
function bybevaeg_pages_overrides_image_styles_alter(&$data) {
  if (isset($data['title_image'])) {

  if ($data['title_image']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['title_image']['effects'][6]['data']['height'] = '300';
  }

  if ($data['title_image']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['title_image']['effects'][6]['data']['width'] = '1000';
  }
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function bybevaeg_pages_overrides_strongarm_alter(&$data) {
  if (isset($data['menu_options_static_page'])) {
    $data['menu_options_static_page']->value['1'] = 'menu-secondary-links'; /* WAS: '' */
  }
}
