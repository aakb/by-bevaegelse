<?php
/**
 * @file
 * bybevaeg_pages_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function bybevaeg_pages_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field
  $overrides["field.node-static_page-field_download.field_instance|display|default|module"]["DELETED"] = TRUE;
  $overrides["field.node-static_page-field_download.field_instance|display|default|type"] = 'hidden';
  $overrides["field.node-static_page-field_download.field_instance|display|default|weight"] = '3';
  $overrides["field.node-static_page-field_links.field_instance|display|default|module"]["DELETED"] = TRUE;
  $overrides["field.node-static_page-field_links.field_instance|display|default|type"] = 'hidden';
  $overrides["field.node-static_page-field_links.field_instance|display|default|weight"] = '2';
  $overrides["field.node-static_page-field_spotbox_title.field_instance|display|default|module"]["DELETED"] = TRUE;
  $overrides["field.node-static_page-field_spotbox_title.field_instance|display|default|type"] = 'hidden';
  $overrides["field.node-static_page-field_spotbox_title.field_instance|display|default|weight"] = '6';
  $overrides["field.node-static_page-field_subject.field_instance|display|default|module"]["DELETED"] = TRUE;
  $overrides["field.node-static_page-field_subject.field_instance|display|default|type"] = 'hidden';
  $overrides["field.node-static_page-field_subject.field_instance|display|default|weight"] = '4';
  $overrides["field.node-static_page-field_tags.field_instance|display|default|module"]["DELETED"] = TRUE;
  $overrides["field.node-static_page-field_tags.field_instance|display|default|type"] = 'hidden';
  $overrides["field.node-static_page-field_tags.field_instance|display|default|weight"] = '5';

  // Exported overrides for: image
  $overrides["image.title_image.effects|0|data|height"] = '300';
  $overrides["image.title_image.effects|0|data|width"] = '1000';

  // Exported overrides for: variable
  $overrides["variable.menu_options_static_page.value|1"] = 'menu-secondary-links';

 return $overrides;
}
