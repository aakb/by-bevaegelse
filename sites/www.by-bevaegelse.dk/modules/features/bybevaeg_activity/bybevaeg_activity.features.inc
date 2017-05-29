<?php
/**
 * @file
 * bybevaeg_activity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bybevaeg_activity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bybevaeg_activity_node_info() {
  $items = array(
    'activity' => array(
      'name' => t('Activity'),
      'base' => 'node_content',
      'description' => t('A description of an activity'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
