<?php
/**
 * @file
 * itkore_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function itkore_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function itkore_pages_image_default_styles() {
  $styles = array();

  // Exported image style: title_image.
  $styles['title_image'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'title_image',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function itkore_pages_node_info() {
  $items = array(
    'static_page' => array(
      'name' => t('Pages'),
      'base' => 'node_content',
      'description' => t('Standard pages on the website, placeable in menus.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
