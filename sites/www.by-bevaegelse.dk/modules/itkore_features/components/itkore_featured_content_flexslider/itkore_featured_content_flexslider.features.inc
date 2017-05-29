<?php
/**
 * @file
 * itkore_featured_content_flexslider.features.inc
 */

/**
 * Implements hook_views_api().
 */
function itkore_featured_content_flexslider_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function itkore_featured_content_flexslider_image_default_styles() {
  $styles = array();

  // Exported image style: flexslider_panorama.
  $styles['flexslider_panorama'] = array(
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1080,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'flexslider_panorama',
  );

  return $styles;
}
