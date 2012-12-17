<?php
/**
 * @file
 * bybevaeg_spotbox_overrides.features.inc
 */

/**
 * Implements hook_views_default_views_alter().
 */
function bybevaeg_spotbox_overrides_views_default_views_alter(&$data) {
  if (isset($data['spotbox'])) {
    $data['spotbox']->display['default']->display_options['fields']['field_content']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['field_content']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['field_manchet']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['field_manchet']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['field_manchet']['hide_empty'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['default']->display_options['fields']['field_news_title_image'] = array(
      'id' => 'field_news_title_image',
      'table' => 'field_data_field_news_title_image',
      'field' => 'field_news_title_image',
      'ui_name' => 'Image (News title image)',
      'label' => '',
      'element_type' => 'div',
      'element_class' => 'imagelink fullwidth',
      'element_label_colon' => FALSE,
      'element_wrapper_type' => '0',
      'element_default_classes' => FALSE,
      'click_sort_column' => 'fid',
      'settings' => array(
        'image_style' => 'spotbox_image',
        'image_link' => 'content',
      ),
    ); /* WAS: '' */
    $data['spotbox']->display['default']->display_options['fields']['field_title_image']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['field_title_image']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['field_title_image']['hide_empty'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['default']->display_options['fields']['field_title_image']['ui_name'] = 'Image (Title image)'; /* WAS: 'Image' */
    $data['spotbox']->display['default']->display_options['fields']['title_1']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['title_1']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['title_1']['hide_empty'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['default']->display_options['fields']['title']['alter']['ellipsis'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['title']['alter']['word_boundary'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['title']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['fields']['title']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['filters']['type']['value']['activity'] = 'activity'; /* WAS: '' */
    $data['spotbox']->display['default']->display_options['row_options']['default_field_elements'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['default']->display_options['row_options']['hide_empty'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
    $data['spotbox']->display['spotbox_image']->display_options['defaults']['hide_admin_links'] = FALSE; /* WAS: '' */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_content']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_content']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['hide_empty'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_title_image']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_title_image']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_title_image']['hide_empty'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['field_title_image']['ui_name'] = 'Image (excluded)'; /* WAS: 'Image' */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title_1']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title_1']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title_1']['hide_empty'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['alter_text'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['ellipsis'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['make_link'] = TRUE; /* WAS: 1 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['word_boundary'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title']['element_default_classes'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['fields']['title']['hide_alter_empty'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_image']->display_options['row_options']['default_field_elements'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_variant2']->display_options['defaults']['hide_admin_links'] = FALSE; /* WAS: '' */
    $data['spotbox']->display['spotbox_variant2']->display_options['row_options']['default_field_elements'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox_variant']->display_options['defaults']['hide_admin_links'] = FALSE; /* WAS: '' */
    $data['spotbox']->display['spotbox_variant']->display_options['row_options']['default_field_elements'] = FALSE; /* WAS: 0 */
    $data['spotbox']->display['spotbox']->display_options['defaults'] = array(
      'hide_admin_links' => FALSE,
    ); /* WAS: '' */
    unset($data['spotbox']->display['default']->display_options['arguments']['nid']['break_phrase']);
    unset($data['spotbox']->display['default']->display_options['arguments']['nid']['default_argument_skip_url']);
    unset($data['spotbox']->display['default']->display_options['arguments']['nid']['not']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_content']['alter']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_content']['empty_zero']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_content']['field_api_classes']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_content']['hide_empty']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['absolute']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['alter_text']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['ellipsis']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['external']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['html']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['make_link']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['nl2br']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['replace_spaces']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['strip_tags']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['trim']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['trim_whitespace']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['alter']['word_boundary']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['empty_zero']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_manchet']['field_api_classes']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_title_image']['alter']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_title_image']['empty_zero']);
    unset($data['spotbox']->display['default']->display_options['fields']['field_title_image']['field_api_classes']);
    unset($data['spotbox']->display['default']->display_options['fields']['title_1']['alter']);
    unset($data['spotbox']->display['default']->display_options['fields']['title_1']['empty_zero']);
    unset($data['spotbox']->display['default']->display_options['fields']['title_1']['link_to_node']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['absolute']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['alter_text']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['external']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['html']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['make_link']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['nl2br']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['replace_spaces']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['strip_tags']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['trim']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['alter']['trim_whitespace']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['empty_zero']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['hide_empty']);
    unset($data['spotbox']->display['default']->display_options['fields']['title']['link_to_node']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_content']['alter']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_content']['empty_zero']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_content']['field_api_classes']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_content']['hide_empty']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['absolute']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['alter_text']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['ellipsis']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['external']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['html']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['make_link']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['nl2br']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['replace_spaces']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['strip_tags']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['trim']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['trim_whitespace']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['alter']['word_boundary']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['empty_zero']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_manchet']['field_api_classes']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_title_image']['alter']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_title_image']['empty_zero']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['field_title_image']['field_api_classes']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title_1']['alter']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title_1']['empty_zero']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title_1']['link_to_node']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['absolute']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['external']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['html']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['nl2br']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['replace_spaces']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['strip_tags']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['trim']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['alter']['trim_whitespace']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['empty_zero']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['hide_empty']);
    unset($data['spotbox']->display['spotbox_image']->display_options['fields']['title']['link_to_node']);
    unset($data['spotbox']->display['spotbox_image']->display_options['row_options']['hide_empty']);
    unset($data['spotbox']->display['spotbox_variant2']->display_options['row_options']['hide_empty']);
    unset($data['spotbox']->display['spotbox_variant']->display_options['row_options']['hide_empty']);
  }
}
