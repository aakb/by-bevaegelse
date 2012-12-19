<?php
/**
 * @file
 * bybevaeg_spotbox_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function bybevaeg_spotbox_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: image
  $overrides["image.spotbox_image.effects|0|data|height"] = '375';
  $overrides["image.spotbox_image.effects|0|data|width"] = '700';

 return $overrides;
}
