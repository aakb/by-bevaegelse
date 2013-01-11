<?php
/**
 * @file
 * Preprocess and alter functions.
 */

/**
 * Implements hook_process_html().
 *
 * Process variables for html.tpl.php
 */
function byib_preprocess_html(&$vars) {
  // Add conditional CSS for IE7 and below.
  drupal_add_css(path_to_theme() . '/css/byib.ie7.css', array(
    'group' => CSS_THEME,
    'browsers' => array(
      'IE' => 'lte IE 7',
      '!IE' => FALSE
    ),
    'weight' => 999, 
    'preprocess' => FALSE,
  ));

  // If tertiary content is not present add a class to body tag.
  if (empty($vars['page']['tertiary_content'])) {
    $vars['classes_array'][] = 'no-tertiary-content';
  }
  // If secondary content is not present add a class to body tag.
  if (empty($vars['page']['secondary_content'])) {
    $vars['classes_array'][] = 'no-secondary-content';
  }
}

/**
 * Implements hook_menu_tree_menu_block().
 */
function byib_menu_tree__menu_block__2($vars) {
  // Add correct class to sub menu
  return '<ul class="sub-menu">'. $vars['tree'] .'</ul>';
}

/**
 * Implements hook_preprocess_field().
 */
function byib_preprocess_field(&$vars) {
  // Add custom class name to specified fields
  switch ($vars['element']['#field_name']) {
    case 'field_title_image':
      $vars['classes_array'][] = 'page-image';
      break;

    case 'field_manchet':
      $vars['classes_array'][] = 'lead';
      break;

    case 'field_content':
      $vars['classes_array'][] = 'page-content';
      break;
  }
}
