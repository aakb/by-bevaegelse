<?php

// We need functions
require_once(drupal_get_path('theme', 'byib') . '/inc/functions.inc');

/*
 * Implements form_system_theme_settings_alter().
 */
function byib_form_system_theme_settings_alter(&$form, $form_state) {
  $path_to_at_core = drupal_get_path('theme', 'byib');

  // Get the byib name, we need it at some stage.
  $theme_name = $form_state['build_info']['args'][0];

  /*
   * CSS class and markup
   */
  $form['byib-settings']['classes'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Classes & Markup'),
    '#description'   => t('Modify the default classes and markup from Drupal.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight'=> -11
  );

  $form['byib-settings']['classes']['menu'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Menus'),
    '#description'   => t('Removes classes from the &lt;li&gt; tag in the menu.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['byib-settings']['classes']['menu']['byib_classes_menu_leaf'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Remove .leaf from the li '),
    '#default_value' => theme_get_setting('byib_classes_menu_leaf')
  );

  $form['byib-settings']['classes']['menu']['byib_classes_menu_has_children'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Remove .has-children from the li '),
    '#default_value' => theme_get_setting('byib_classes_menu_has_children')
  );

  $form['byib-settings']['classes']['menu']['byib_classes_menu_items_mlid'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Remove the menu-mlid-[mid] class'),
    '#default_value' => theme_get_setting('byib_classes_menu_items_mlid')
  );

  /*
   * Sticky menus
   */

  $form['byib-settings']['sticky_menus'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sticky menus'),
    '#description' => t('<h3>Sticky menus</h3><p>Here you can choose which menus you want to be sticky.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight'=> -10,
  );
  
  // Main menu sticky
  $form['byib-settings']['sticky_menus']['main_menu_sticky'] = array(
    '#type' => 'checkbox',
    '#title' => t('Main menu sticky'),
    '#description' => t('By checking this setting the main menu will be sticky (stick to the top of the page when scrolling).'),
    '#default_value' => theme_get_setting('main_menu_sticky'),
  );  

  /*
   * Polyfill settings
   */
  $form['byib-settings']['polyfills'] = array(
    '#type' => 'fieldset',
    '#title' => t('Polyfills'),
    '#description' => t('<h3>Polyfills</h3><p>Here you can enable commonly used Polyfills supplied with the core theme.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight'=> -10,
  );

  $form['byib-settings']['polyfills']['fills'] = array(
    '#type' => 'fieldset',
    '#title' => t('Polyfills'),
  );

  // HTML5 shiv
  $form['byib-settings']['polyfills']['fills']['load_html5js'] = array(
    '#type' => 'checkbox',
    '#title' => t('HTML5 support in IE'),
    '#description' => t('By checking this setting the site will load the <a href="!link" target="_blank">html5shiv</a>. Turning this off will be bad news for IE6-8.', array('!link' => '//github.com/aFarkas/html5shiv')),
    '#default_value' => theme_get_setting('load_html5js'),
  );

  // Selectivizr
  $form['byib-settings']['polyfills']['fills']['load_selectivizr'] = array(
    '#type' => 'checkbox',
    '#title' => t('Selectivizr'),
    '#description' => t('<a href="!link" target="_blank">Selectivizr</a> is a JavaScript utility that emulates CSS3 pseudo-classes and attribute selectors in Internet Explorer 6-8.', array('!link' => 'http://selectivizr.com')),
    '#default_value' => theme_get_setting('load_selectivizr'),
  );

  // Scalefix
  $form['byib-settings']['polyfills']['fills']['load_scalefixjs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Scalefix for iOS'),
    '#description' => t('Fixes the iOS Orientationchange zoom bug.'),
    '#default_value' => theme_get_setting('load_scalefixjs'),
    '#states' => array(
      'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
    ),
  );


  /*
   * Plugins
   */
  $form['byib-settings']['plugins'] = array(
    '#type' => 'fieldset',
    '#title' => t('Plugins'),
    '#description' => t('<h3>Plugins</h3><p>Here you can enable plugins supplied with the core theme.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight'=> -10,
  );

  // Equalize
  $form['byib-settings']['plugins']['load_equalize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Equalize'),
    '#description' => t('<a href="!link" target="_blank">Equalize</a> is a jQuery plugin for equalizing the height or width of elements.', array('!link' => 'https://github.com/tsvensen/equalize.js/')),
    '#default_value' => theme_get_setting('load_equalize'),
  );

  // Unset CSS
  $form['byib-settings']['cssexcludes'] = array(
  '#type' => 'fieldset',
  '#title' => t('Unset CSS'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  '#weight' => -9,
);
  $form['byib-settings']['cssexcludes']['enable_exclude_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Unset CSS Files'),
    '#description' => t('Options to unset (exclude) CSS files from loading in your theme - includes settings for Core modules, CSS added by Libaries and your own declared exclusions (see your themes info file under "Stylesheets").'),
    '#default_value' => theme_get_setting('enable_exclude_css'),
  );
  // Exclude CSS
  $enable_exclude_css = isset($form_state['values']['enable_exclude_css']);
  if (($enable_exclude_css && $form_state['values']['enable_exclude_css'] == 1) || (!$enable_exclude_css && $form['byib-settings']['cssexcludes']['enable_exclude_css']['#default_value'] == 1)) {
    require_once($path_to_at_core . '/inc/settings.cssexclude.inc');
  }

  // Collapse annoying forms
  $form['theme_settings']['#collapsible'] = TRUE;
  $form['theme_settings']['#collapsed'] = TRUE;
  $form['theme_settings']['#weight'] = 50;
  $form['logo']['#collapsible'] = TRUE;
  $form['logo']['#collapsed'] = TRUE;
  $form['logo']['#weight'] = 50;
  $form['favicon']['#collapsible'] = TRUE;
  $form['favicon']['#collapsed'] = TRUE;
  $form['favicon']['#weight'] = 50;
}
