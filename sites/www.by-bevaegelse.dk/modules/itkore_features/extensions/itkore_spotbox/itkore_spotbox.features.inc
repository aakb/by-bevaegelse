<?php
/**
 * @file
 * itkore_spotbox.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function itkore_spotbox_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function itkore_spotbox_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function itkore_spotbox_image_default_styles() {
  $styles = array();

  // Exported image style: spotbox_image.
  $styles['spotbox_image'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 375,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'spotbox_image',
  );

  return $styles;
}
