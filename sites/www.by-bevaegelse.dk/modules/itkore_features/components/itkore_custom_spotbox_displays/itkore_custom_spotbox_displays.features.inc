<?php
/**
 * @file
 * itkore_custom_spotbox_displays.features.inc
 */

/**
 * Implements hook_views_api().
 */
function itkore_custom_spotbox_displays_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function itkore_custom_spotbox_displays_image_default_styles() {
  $styles = array();

  // Exported image style: spotbox_external_link_image.
  $styles['spotbox_external_link_image'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 376,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'spotbox_external_link_image',
  );

  return $styles;
}
