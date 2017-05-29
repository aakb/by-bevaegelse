<?php
/**
 * @file
 * itkore_custom_spotbox.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function itkore_custom_spotbox_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function itkore_custom_spotbox_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function itkore_custom_spotbox_node_info() {
  $items = array(
    'spotbox' => array(
      'name' => t('Spotbox'),
      'base' => 'node_content',
      'description' => t('Create a spotbox that can be inserted into other pages on the site. Can link to other webpages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
