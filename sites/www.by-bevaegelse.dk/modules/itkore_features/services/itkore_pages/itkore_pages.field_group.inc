<?php
/**
 * @file
 * itkore_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function itkore_pages_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spotbox|node|static_page|form';
  $field_group->group_name = 'group_spotbox';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'static_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Spotbox',
    'weight' => '3',
    'children' => array(
      0 => 'field_spotbox_title',
      1 => 'field_spotbox_text',
      2 => '_add_new_field',
      3 => 'field_spotbox_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-spotbox field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_spotbox|node|static_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Spotbox');

  return $field_groups;
}
