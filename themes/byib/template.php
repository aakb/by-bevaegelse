<?php
/**
 * @file
 * Preprocess and alter functions.
 */

/**
 * Implements hook_preprocess_block().
 */
//function byib_preprocess_block(&$vars) {
//  // Load region
//  $current_region = $vars['elements']['#block']->region;
//
//  // Add classes based on module & region
//  if ($current_region == 'secondary_content' && $vars['elements']['#block']->module == 'menu_block') {
//
//    $vars['attributes_array']['class'][] = 'sub-menu';
//
//  }
//}

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
    
    default:
      
      break;
  }
}
