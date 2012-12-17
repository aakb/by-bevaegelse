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
  $overrides["field.node-static_page-field_content.field_instance|required"] = 0;

 return $overrides;
}
