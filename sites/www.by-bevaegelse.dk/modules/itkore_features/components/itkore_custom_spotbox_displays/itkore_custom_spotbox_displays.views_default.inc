<?php
/**
 * @file
 * itkore_custom_spotbox_displays.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function itkore_custom_spotbox_displays_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'spotbox_external_link';
  $view->description = 'Spotboxes with external link';
  $view->tag = 'itkore';
  $view->base_table = 'node';
  $view->human_name = 'Custom Spotbox';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'block block-secondary';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Excluded: Link */
  $handler->display->display_options['fields']['field_spotbox_external_link']['id'] = 'field_spotbox_external_link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['table'] = 'field_data_field_spotbox_external_link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['field'] = 'field_spotbox_external_link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['ui_name'] = 'Excluded: Link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['label'] = '';
  $handler->display->display_options['fields']['field_spotbox_external_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['path'] = '[field_spotbox_external_link-url]';
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['rel'] = 'external';
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['link_class'] = 'link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_spotbox_external_link']['type'] = 'link_plain';
  /* Field: Block title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Block title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2 class="block-title"><a href="[field_spotbox_external_link]">[title]</a></h2>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_spotbox_external_link]';
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'block-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Linked image */
  $handler->display->display_options['fields']['field_spotbox_image']['id'] = 'field_spotbox_image';
  $handler->display->display_options['fields']['field_spotbox_image']['table'] = 'field_data_field_spotbox_image';
  $handler->display->display_options['fields']['field_spotbox_image']['field'] = 'field_spotbox_image';
  $handler->display->display_options['fields']['field_spotbox_image']['ui_name'] = 'Linked image';
  $handler->display->display_options['fields']['field_spotbox_image']['label'] = '';
  $handler->display->display_options['fields']['field_spotbox_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_image']['alter']['path'] = '[field_spotbox_external_link]';
  $handler->display->display_options['fields']['field_spotbox_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_spotbox_image']['element_wrapper_class'] = 'fullwidth imagelink';
  $handler->display->display_options['fields']['field_spotbox_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_spotbox_image']['settings'] = array(
    'image_style' => 'spotbox_external_link_image',
    'image_link' => '',
  );
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_spotbox_text']['id'] = 'field_spotbox_text';
  $handler->display->display_options['fields']['field_spotbox_text']['table'] = 'field_data_field_spotbox_text';
  $handler->display->display_options['fields']['field_spotbox_text']['field'] = 'field_spotbox_text';
  $handler->display->display_options['fields']['field_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_spotbox_text']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_spotbox_text']['element_class'] = 'text-content';
  $handler->display->display_options['fields']['field_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_text']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_spotbox_text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_text']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_text']['hide_alter_empty'] = FALSE;
  /* Field: Content: Download */
  $handler->display->display_options['fields']['field_download']['id'] = 'field_download';
  $handler->display->display_options['fields']['field_download']['table'] = 'field_data_field_download';
  $handler->display->display_options['fields']['field_download']['field'] = 'field_download';
  $handler->display->display_options['fields']['field_download']['label'] = '';
  $handler->display->display_options['fields']['field_download']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_download']['element_class'] = 'link';
  $handler->display->display_options['fields']['field_download']['element_label_type'] = 'em';
  $handler->display->display_options['fields']['field_download']['element_label_class'] = 'label';
  $handler->display->display_options['fields']['field_download']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_download']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_download']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_download']['click_sort_column'] = 'fid';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['id'] = 'field_spotbox_external_link_1';
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['table'] = 'field_data_field_spotbox_external_link';
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['field'] = 'field_spotbox_external_link';
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['element_class'] = 'link';
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_external_link_1']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'spotbox' => 'spotbox',
  );

  /* Display: Spotbox: Default */
  $handler = $view->new_display('block', 'Spotbox: Default', 'spotbox_external_default');
  $handler->display->display_options['display_description'] = 'Standard spotbox with external link';
  $handler->display->display_options['block_description'] = 'Standard spotbox';

  /* Display: Spotbox: Alternative style */
  $handler = $view->new_display('block', 'Spotbox: Alternative style', 'spotbox_external_variant');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'style-alternative block block-secondary';
  $handler->display->display_options['display_description'] = 'Alternatively styled spotbox with external link';
  $handler->display->display_options['block_description'] = 'Alternative style spotbox';

  /* Display: Spotbox: Image/Video */
  $handler = $view->new_display('block', 'Spotbox: Image/Video', 'spotbox_external_image');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'block block-secondary block-image';
  $handler->display->display_options['display_description'] = 'Image/video style spotbox';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Excluded: Link */
  $handler->display->display_options['fields']['field_spotbox_external_link']['id'] = 'field_spotbox_external_link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['table'] = 'field_data_field_spotbox_external_link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['field'] = 'field_spotbox_external_link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['ui_name'] = 'Excluded: Link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['label'] = '';
  $handler->display->display_options['fields']['field_spotbox_external_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['path'] = '[field_spotbox_external_link-url]';
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['rel'] = 'external';
  $handler->display->display_options['fields']['field_spotbox_external_link']['alter']['link_class'] = 'link';
  $handler->display->display_options['fields']['field_spotbox_external_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_external_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_spotbox_external_link']['type'] = 'link_url';
  /* Field: Image */
  $handler->display->display_options['fields']['field_spotbox_image']['id'] = 'field_spotbox_image';
  $handler->display->display_options['fields']['field_spotbox_image']['table'] = 'field_data_field_spotbox_image';
  $handler->display->display_options['fields']['field_spotbox_image']['field'] = 'field_spotbox_image';
  $handler->display->display_options['fields']['field_spotbox_image']['ui_name'] = 'Image';
  $handler->display->display_options['fields']['field_spotbox_image']['label'] = '';
  $handler->display->display_options['fields']['field_spotbox_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_image']['alter']['path'] = '[field_spotbox_external_link]';
  $handler->display->display_options['fields']['field_spotbox_image']['alter']['link_class'] = 'imagelink fullwidth overlay';
  $handler->display->display_options['fields']['field_spotbox_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_spotbox_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_spotbox_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_spotbox_image']['settings'] = array(
    'image_style' => 'spotbox_external_link_image',
    'image_link' => '',
  );
  /* Field: Block title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Block title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_spotbox_image]
<div class="coverlayer"><h2 class="block-title">[title]</h2></div>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_spotbox_external_link]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'imagewrapper fullwidth imagelink';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_spotbox_text']['id'] = 'field_spotbox_text';
  $handler->display->display_options['fields']['field_spotbox_text']['table'] = 'field_data_field_spotbox_text';
  $handler->display->display_options['fields']['field_spotbox_text']['field'] = 'field_spotbox_text';
  $handler->display->display_options['fields']['field_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_spotbox_text']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_spotbox_text']['element_class'] = 'text-content';
  $handler->display->display_options['fields']['field_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_text']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_spotbox_text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_spotbox_text']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_spotbox_text']['hide_alter_empty'] = FALSE;
  /* Field: Content: Download */
  $handler->display->display_options['fields']['field_download']['id'] = 'field_download';
  $handler->display->display_options['fields']['field_download']['table'] = 'field_data_field_download';
  $handler->display->display_options['fields']['field_download']['field'] = 'field_download';
  $handler->display->display_options['fields']['field_download']['label'] = '';
  $handler->display->display_options['fields']['field_download']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_download']['element_class'] = 'link';
  $handler->display->display_options['fields']['field_download']['element_label_type'] = 'em';
  $handler->display->display_options['fields']['field_download']['element_label_class'] = 'label';
  $handler->display->display_options['fields']['field_download']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_download']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_download']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_download']['click_sort_column'] = 'fid';
  $handler->display->display_options['block_description'] = 'Image/video spotbox';

  /* Display: Spotbox: Alternative 2 */
  $handler = $view->new_display('block', 'Spotbox: Alternative 2', 'custom_spotbox_variant_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'style-alt2 block block-secondary';
  $handler->display->display_options['display_description'] = 'Alternatively styled spotbox with external link';
  $handler->display->display_options['block_description'] = 'Alternative 2 spotbox';
  $translatables['spotbox_external_link'] = array(
    t('Master'),
    t('mere'),
    t('Apply'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('[title]'),
    t('<h2 class="block-title"><a href="[field_spotbox_external_link]">[title]</a></h2>'),
    t('All'),
    t('Spotbox: Default'),
    t('Standard spotbox with external link'),
    t('more'),
    t('Standard spotbox'),
    t('Spotbox: Alternative style'),
    t('Alternatively styled spotbox with external link'),
    t('Alternative style spotbox'),
    t('Spotbox: Image/Video'),
    t('Image/video style spotbox'),
    t('[field_spotbox_image]
<div class="coverlayer"><h2 class="block-title">[title]</h2></div>'),
    t('Image/video spotbox'),
    t('Spotbox: Alternative 2'),
    t('Alternative 2 spotbox'),
  );
  $export['spotbox_external_link'] = $view;

  return $export;
}
