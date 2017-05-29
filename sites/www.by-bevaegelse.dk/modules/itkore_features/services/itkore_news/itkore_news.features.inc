<?php
/**
 * @file
 * itkore_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function itkore_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function itkore_news_image_default_styles() {
  $styles = array();

  // Exported image style: news_title_image.
  $styles['news_title_image'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'news_title_image',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function itkore_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('News article. Listed on the news pages. Not placeable in menus.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
