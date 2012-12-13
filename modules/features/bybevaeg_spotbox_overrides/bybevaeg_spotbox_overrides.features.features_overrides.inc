<?php
/**
 * @file
 * bybevaeg_spotbox_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function bybevaeg_spotbox_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.spotbox.display|default|display_options|arguments|nid|break_phrase"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|arguments|nid|default_argument_skip_url"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|arguments|nid|not"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_content|alter"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_content|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_content|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_content|field_api_classes"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_content|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_content|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|absolute"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|alter_text"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|ellipsis"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|external"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|html"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|make_link"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|nl2br"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|replace_spaces"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|strip_tags"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|trim"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|trim_whitespace"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|alter|word_boundary"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|field_api_classes"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_manchet|hide_empty"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_news_title_image"] = array(
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
  );
  $overrides["views_view.spotbox.display|default|display_options|fields|field_title_image|alter"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_title_image|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_title_image|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_title_image|field_api_classes"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_title_image|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_title_image|hide_empty"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|field_title_image|ui_name"] = 'Image (Title image)';
  $overrides["views_view.spotbox.display|default|display_options|fields|title_1|alter"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title_1|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title_1|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title_1|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title_1|hide_empty"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title_1|link_to_node"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|absolute"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|alter_text"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|ellipsis"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|external"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|html"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|make_link"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|nl2br"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|replace_spaces"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|strip_tags"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|trim"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|trim_whitespace"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|alter|word_boundary"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|fields|title|link_to_node"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|filters|type|value|activity"] = 'activity';
  $overrides["views_view.spotbox.display|default|display_options|row_options|default_field_elements"] = FALSE;
  $overrides["views_view.spotbox.display|default|display_options|row_options|hide_empty"] = TRUE;
  $overrides["views_view.spotbox.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|defaults|hide_admin_links"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_content|alter"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_content|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_content|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_content|field_api_classes"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_content|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_content|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|absolute"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|alter_text"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|ellipsis"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|external"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|html"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|make_link"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|nl2br"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|replace_spaces"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|strip_tags"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|trim"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|trim_whitespace"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|alter|word_boundary"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|field_api_classes"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_manchet|hide_empty"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_title_image|alter"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_title_image|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_title_image|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_title_image|field_api_classes"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_title_image|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_title_image|hide_empty"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|field_title_image|ui_name"] = 'Image (excluded)';
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title_1|alter"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title_1|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title_1|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title_1|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title_1|hide_empty"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title_1|link_to_node"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|absolute"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|alter_text"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|ellipsis"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|external"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|html"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|make_link"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|nl2br"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|replace_spaces"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|strip_tags"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|trim"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|trim_whitespace"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|alter|word_boundary"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|element_default_classes"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|hide_alter_empty"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|fields|title|link_to_node"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|row_options|default_field_elements"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_image|display_options|row_options|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_variant2|display_options|defaults|hide_admin_links"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_variant2|display_options|row_options|default_field_elements"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_variant2|display_options|row_options|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox_variant|display_options|defaults|hide_admin_links"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_variant|display_options|row_options|default_field_elements"] = FALSE;
  $overrides["views_view.spotbox.display|spotbox_variant|display_options|row_options|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.spotbox.display|spotbox|display_options|defaults"] = array(
    'hide_admin_links' => FALSE,
  );

 return $overrides;
}
