<?php
/**
 * @file
 * itkore_news_display.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function itkore_news_display_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function itkore_news_display_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function itkore_news_display_image_default_styles() {
  $styles = array();

  // Exported image style: news_large.
  $styles['news_large'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'news_large',
  );

  // Exported image style: news_thumbnail.
  $styles['news_thumbnail'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 188,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'news_thumbnail',
  );

  return $styles;
}
