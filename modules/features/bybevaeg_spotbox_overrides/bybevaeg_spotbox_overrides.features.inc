<?php
/**
 * @file
 * bybevaeg_spotbox_overrides.features.inc
 */

/**
 * Implements hook_image_styles_alter().
 */
function bybevaeg_spotbox_overrides_image_styles_alter(&$data) {
  if (isset($data['spotbox_image'])) {

  if ($data['spotbox_image']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['spotbox_image']['effects']['0']['data']['height'] = '375';
  }

  if ($data['spotbox_image']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['spotbox_image']['effects']['0']['data']['width'] = '700';
  }
  }
}
