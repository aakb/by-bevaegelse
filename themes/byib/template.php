<?php
/**
 * @file
 * Preprocess and alter functions.
 */

global $theme_key, $path_to_byib_core;
$theme_key = $GLOBALS['theme_key'];
$path_to_byib_core = drupal_get_path('theme', 'byib');

//Includes frequently used theme functions that gets theme info, css files etc.
include_once($path_to_byib_core . '/inc/functions.inc');


/**
 * Preprocess variables for html.tpl.php
 */
function byib_preprocess_html(&$vars) {
  global $theme_key, $language;
  $theme_name = $theme_key;

  // Set variable for the base path
  $vars['base_path'] = base_path();

  // Clean up the lang attributes.
  $vars['html_attributes'] = 'lang="' . $language->language . '" dir="' . $language->dir . '"';

  // Build an array of polyfilling scripts
  $vars['polyfills_array'] = '';
  $vars['polyfills_array'] = byib_load_polyfills($theme_name, $vars);

  // If tertiary content is not present add a class to body tag.
  if (empty($vars['page']['tertiary_content'])) {
    $vars['classes_array'][] = 'no-tertiary-content';
  }
  // If secondary content is not present add a class to body tag.
  if (empty($vars['page']['secondary_content'])) {
    $vars['classes_array'][] = 'no-secondary-content';
  }

  // Add conditional CSS for IE7
  drupal_add_css(path_to_theme() . '/css/byib.ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));

  // Add conditional CSS for IE8
  drupal_add_css(path_to_theme() . '/css/byib.ie8.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));

  // Add conditional CSS for IE9
  drupal_add_css(path_to_theme() . '/css/byib.ie9.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 9', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));

  // Load byib plugins
  byib_load_plugins();
}


/**
 * Implements hook_process_html().
 *
 * Process variables for html.tpl.php
 */
function byib_process_html(&$vars) {
  // This code is copied from Adaptive Theme, at_core/inc/process.inc.
  // It wraps the required polyfills scripts into a conditional comment.
  if (!empty($vars['polyfills_array'])) {
    $vars['polyfills'] = drupal_static('byib_process_html_polyfills');
    if (empty($vars['polyfills'])) {
      $polyfills = array();
      foreach ($vars['polyfills_array'] as $key => $value) {
        foreach ($value as $k => $v) {
          $polyfills[$k][] = implode("\n", $v);
        }
      }
      foreach ($polyfills as $kv => $kvp) {
        $polyfills_scripts[$kv] = implode("\n", $kvp);
      }
      $vars['polyfills'] = byib_theme_conditional_scripts($polyfills_scripts);
    }
  }
  else {
    $vars['polyfills'] = '';
  }

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
  if (!$vars['is_front']) {
    // Add unique class for each page.
    $path = drupal_get_path_alias($_GET['q']);
    // Add unique class for each website section.
    list($section, ) = explode('/', $path, 2);
    $arg = explode('/', $_GET['q']);
    if ($arg[0] == 'node' && isset($arg[1])) {
      if ($arg[1] == 'add') {
        $section = 'node-add';
      }
      elseif (isset($arg[2]) && is_numeric($arg[1]) && ($arg[2] == 'edit' || $arg[2] == 'delete')) {
        $section = 'node-' . $arg[2];
      }
    }
    $vars['classes_array'][] = drupal_html_class('section-' . $section);
  }
  // Store the menu item since it has some useful information.
  $vars['menu_item'] = menu_get_item();
  if ($vars['menu_item']) {
    switch ($vars['menu_item']['page_callback']) {
      case 'views_page':
        // Is this a Views page?
        $vars['classes_array'][] = 'page-views';
        break;
      case 'page_manager_page_execute':
      case 'page_manager_node_view':
      case 'page_manager_contact_site':
        // Is this a Panels page?
        $vars['classes_array'][] = 'page-panels';
        break;
    }
  }
}

/**
 * Implements hook_css_alter().
 */
function byib_css_alter(&$css) {
  global $theme_key;

  // Never allow this to run in our admin theme and only if the extension is enabled.
  if (theme_get_setting('enable_exclude_css') === 1) {

    // Get $css_data from the cache
    if ($cache = cache_get('byib_get_css_files')) {
      $css_data = $cache->data;
    }
    else {
      $css_data = byib_get_css_files($theme_key);
    }

    // We need the right theme name to get the theme settings
    $_get_active_theme_data = array_pop($css_data);
    if ($_get_active_theme_data['type'] == 'theme') {
      $theme_name = $_get_active_theme_data['source'];
    }
    else {
      $theme_name = $theme_key;
    }

    // Get the theme setting and unset files
    foreach ($css_data as $key => $value) {
      $setting = 'unset_css_' . drupal_html_class($key);
      if (theme_get_setting($setting, $theme_name) === 1) {
        if (isset($css[$key])) {
          unset($css[$key]);
        }
      }
    }
  }
}

/**
 * Implements hook_preprocess_panels_pane().
 *
 */
function byib_preprocess_panels_pane(&$vars) {
  // Suggestions base on sub-type.
  $vars['theme_hook_suggestions'][] = 'panels_pane__' . str_replace('-', '__', $vars['pane']->subtype);

  // Suggestions on panel pane
  $vars['theme_hook_suggestions'][] = 'panels_pane__' . $vars['pane']->panel;
}

/**
 * Render callback.
 *
 * Remove panels div separator.
 */
function byib_panels_default_style_render_region($vars) {
  $output = '';
  $output .= implode('', $vars['panes']);
  return $output;
}

/**
 * Implements theme_menu_tree().
 *
 * Addes wrapper clases for menus.
 */
function byib_menu_tree__menu_block__1($vars) {
  return '<ul class="main-menu">' . $vars['tree'] . '</ul>';
}

function byib_menu_tree__menu_block__2($vars) {
  // Add correct class to sub menu
  return '<ul class="sub-menu">'. $vars['tree'] .'</ul>';
}


/**
 * Implements theme_menu_link().
 */
function byib_menu_link($vars) {

  // Remove classes.
  $remove = array();

  // Remove .leaf.
  if(theme_get_setting('byib_classes_menu_leaf')){
    $remove[] .= "leaf";
  }

  // Remove .has-children.
  if(theme_get_setting('byib_classes_menu_has_children')){
    $remove[] .= "has-children";
  }

  // Remove .collapsed, .expanded and expandable.
  if(theme_get_setting('byib_classes_menu_collapsed')){
    $remove[] .= "collapsed";
    $remove[] .= "expanded";
    $remove[] .= "expandable";
  }

  // Remove the classes.
  if($remove){
    $vars['element']['#attributes']['class'] = array_diff($vars['element']['#attributes']['class'],$remove);
  }

  // Remove menu-mlid-[NUMBER].
  if(theme_get_setting('byib_classes_menu_items_mlid')){
    $vars['element']['#attributes']['class'] = preg_grep('/^menu-mlid-/', $vars['element']['#attributes']['class'], PREG_GREP_INVERT);
  }

  // Check if the class array is empty.
  if(empty($vars['element']['#attributes']['class'])){
    unset($vars['element']['#attributes']['class']);
  }

  $element = $vars['element'];

  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '><span>' . $output . $sub_menu . "</span></li>\n";
}

/**
 * Polyfill is used to enable HTML5 on browsers who doesn't natively support it.
 * Polyfill adds the missing functionality by 'filling' in scripts that add the
 * HTML5 functionality the browser doesn't offer.
 *
 * Return an array of filenames (scripts) to include.
 *
 * @param string $theme_name  :   Name of the theme.
 */
function byib_load_polyfills($theme_name) {
  global $path_to_byib_core;

  // Get the info file data
  $info = byib_get_info($theme_name);

  // Build an array of polyfilling scripts
  $polyfills_array = drupal_static('byib_preprocess_html_polyfills_array');
  if (empty($polyfills_array)) {
    // Info file loaded conditional scripts
    $theme_path = drupal_get_path('theme', $theme_name);
    if (array_key_exists('ie_scripts', $info)) {
      foreach ($info['ie_scripts'] as $condition => $ie_scripts_path) {
        foreach ($ie_scripts_path as $key => $value) {
          $filepath = $theme_path . '/' . $value;
          $polyfills_array['info'][$condition][] = byib_theme_script($filepath);
        }
      }
    }
    // Byib Core Polyfills
    $polly = '';
    $polly_settings_array = array(
      'load_html5js',
      'load_selectivizr',
      'load_scalefixjs', // loaded directly by polly_wants_a_cracker(), its never returned
    );
    foreach ($polly_settings_array as $polly_setting) {
      $polly[$polly_setting] = theme_get_setting($polly_setting, $theme_name);
    }
    $backed_crackers = byib_polly_wants_a_cracker($polly, $theme_name);
    foreach ($backed_crackers as $cupboard => $flavors) {
      foreach ($flavors as $key => $value) {
        $filepath = $path_to_byib_core . '/' . $value;
        $polyfills_array['byib'][$cupboard][] = byib_theme_script($filepath);
      }
    }
  }

  return $polyfills_array;
}

/**
 * Allows us to add script plugins to the theme via theme settings.
 * Ex. add a javascript depending on the settings in the theme.
 *
 * @param $theme_name
 */
function byib_load_plugins() {
  global $path_to_byib_core;

  // If sticky menus is enabled in the theme load it.
  if (theme_get_setting('main_menu_sticky')) {

    // Add variable to js so we can check if it is set
    drupal_add_js(array('byib' => array('main_menu_sticky' => theme_get_setting('main_menu_sticky'),)), 'setting');

  }


  // If equalize is enabled in the theme load it.
  if (theme_get_setting('load_equalize')) {

    // Add the script
    drupal_add_js($path_to_byib_core . '/scripts/equalize.js');

    // Add variable to js so we can check if it is set
    drupal_add_js(array('byib' => array('load_equalize' => theme_get_setting('load_equalize'),)), 'setting');

  }

}

/**
 * Implements hook_theme_script().
 *
 * Since Drupal 7 does not (yet) support the 'browser' option in drupal_add_js()
 * Byib provides a way to load scripts inside conditional comments.
 * This function wraps a file in script elements and returns a string.
 *
 * @param $filepath, path to the file.
 */
function byib_theme_script($filepath) {
  $script = '';

  // We need the default query string for cache control finger printing
  $query_string = variable_get('css_js_query_string', '0');

  if (file_exists($filepath)) {
    $file = file_create_url($filepath);
    $script = '<script src="' . $file . '?' . $query_string . '"></script>';
  }

  return $script;
}

/**
 * Return themed scripts in Conditional Comments.
 *
 * Since Drupal 7 does not (yet) support the 'browser' option in drupal_add_js()
 * Adaptivetheme provides a way to load scripts inside conditional comments.
 * This function will return a string for printing into a template, its
 * akin to a real theme_function but its not.
 *
 * @param $ie_scripts, an array of themed scripts.
 */
function byib_theme_conditional_scripts($ie_scripts) {
  $themed_scripts = drupal_static(__FUNCTION__, array());
  if (empty($themed_scripts)) {
    $cc_scripts = array();

    foreach ($ie_scripts as $conditional_comment => $conditional_scripts) {
      $cc_scripts[] = '<!--[if ' . $conditional_comment . ']>' . "\n" . $conditional_scripts . "\n" . '<![endif]-->' . "\n";
    }
    $themed_scripts = implode("\n", $cc_scripts);
  }

  return $themed_scripts;
}

/**
 * Polyfills.
 *
 * This function does two seperate operations. First it attaches a condition
 * to each Polyfill which can be either an IE conditional comment or 'all'.
 * Polyfills with 'all' are loaded immediatly via drupal_add_js(), those with
 * an IE CC are returned for further processing. This function is hard coded
 * to support only those scripts supplied by the core theme, if you need to load
 * a script for IE use the info file feature.
 *
 * @param $polly
 * @param $theme_name
 */
function byib_polly_wants_a_cracker($polly, $theme_name) {
  global $path_to_byib_core;

  $baked_crackers = drupal_static(__FUNCTION__, array());
  if (empty($baked_crackers)) {
    if (in_array(1, $polly)) {

      $crackers = array();

      // HTML5 Shiv
      if ($polly['load_html5js'] === 1) {
        $crackers['all'][] = 'scripts/html5shiv.js';
      }
      // Selectivizr
      if ($polly['load_selectivizr'] === 1) {
        $crackers['all'][] = 'scripts/selectivizr-min.js';
      }
      // Scalefix.js
      if ($polly['load_scalefixjs'] === 1) {
        $crackers['all'][] = 'scripts/scalefix.js';
      }

      // Load Polyfills
      if (!empty($crackers)) {

        // We need the default query string for cache control finger printing
        $query_string = variable_get('css_js_query_string', '0');

        // "all" - no conditional comment needed, use drupal_add_js()
        if (isset($crackers['all'])) {
          foreach ($crackers['all'] as $script) {
            drupal_add_js($path_to_byib_core . '/' . $script, array(
              'type' => 'file',
              'scope' => 'header',
              'group' => JS_THEME,
              'preprocess' => TRUE,
              'cache' => TRUE,
              )
            );
          }
        }
      }
    }
  }

  return $baked_crackers;
}

/**
 * Return the info file array for a particular theme, usually the active theme.
 * Simple wrapper function for list_themes().
 *
 * @param $theme_name
 */
function byib_get_info($theme_name) {
  $info = drupal_static(__FUNCTION__, array());
  if (empty($info)) {
    $themes = list_themes();
    foreach ($themes as $key => $value) {
      if ($theme_name == $key) {
        $info = $themes[$theme_name]->info;
      }
    }
  }

  return $info;
}


/**
 * Implements hook_preprocess_views_view_unformatted().
 *
 * Overwrite views row classes
 */
function byib_preprocess_views_view_unformatted(&$vars) {

  // Class names for overwriting
  $row_first = "first";
  $row_last  = "last";

  $view = $vars['view'];
  $rows = $vars['rows'];

  // Set arrays
  $vars['classes_array'] = array();
  $vars['classes'] = array();

  // Variables
  $count = 0;
  $max = count($rows);

  // Loop through the rows and overwrite the classes, its importent that the
  // $row variable is here, as it's the $id that we need.
  foreach ($rows as $id => $row) {
    $count++;

    $vars['classes'][$id][] = $count % 2 ? 'odd' : 'even';

    if ($count == 1) {
      $vars['classes'][$id][] = $row_first;
    }
    if ($count == $max) {
      $vars['classes'][$id][] = $row_last;
    }

    if ($row_class = $view->style_plugin->get_row_class($id)) {
      $vars['classes'][$id][] = $row_class;
    }

    if ( $vars['classes']  && $vars['classes'][$id] ){
      $vars['classes_array'][$id] = implode(' ', $vars['classes'][$id]);
    } else {
      $vars['classes_array'][$id] = '';
    }
  }
}

/**
 * Implements theme_item_list().
 *
 * This is the default theme function. With the wrapper div removed.
 *
 */
function byib_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];
  $output = '';

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      $data = '';
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 0) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items - 1) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  return $output;
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

/**
 * Overrides the webform view message theme function, we want to hide that message on closed forms.
 *
 * Display a message to a user if they are not allowed to fill out a form.
 *
 * @param $node
 *   The webform node object.
 * @param $teaser
 *   If this webform is being displayed as the teaser view of the node.
 * @param $page
 *   If this webform node is being viewed as the main content of the page.
 * @param $submission_count
 *   The number of submissions this user has already submitted. Not calculated
 *   for anonymous users.
 * @param $user_limit_exceeded
 *   Boolean value if the submission limit for this user has been exceeded.
 * @param $total_limit_exceeded
 *   Boolean value if the total submission limit has been exceeded.
 * @param $allowed_roles
 *   A list of user roles that are allowed to submit this webform.
 * @param $closed
 *   Boolean value if submissions are closed.
 */
function byib_webform_view_messages($variables) {
  global $user;

  $node = $variables['node'];
  $teaser = $variables['teaser'];
  $page = $variables['page'];
  $submission_count = $variables['submission_count'];
  $user_limit_exceeded = $variables['user_limit_exceeded'];
  $total_limit_exceeded = $variables['total_limit_exceeded'];
  $allowed_roles = $variables['allowed_roles'];
  $closed = $variables['closed'];
  $cached = $variables['cached'];

  $type = 'status';

  if ($closed) {
    // message removed
  }
  // If open and not allowed to submit the form, give an explanation.
  elseif (array_search(TRUE, $allowed_roles) === FALSE && $user->uid != 1) {
    if (empty($allowed_roles)) {
      // No roles are allowed to submit the form.
      $message = t('No one allowed to submit this form');
    }
    elseif (isset($allowed_roles[2])) {
      // The "authenticated user" role is allowed to submit and the user is currently logged-out.
      $login = url('user/login', array('query' => drupal_get_destination()));
      $register = url('user/register', array('query' => drupal_get_destination()));
      if (variable_get('user_register', 1) == 0) {
        $message = t('You must <a href="!login">login</a> to view this form.', array('!login' => $login));
      }
      else {
        $message = t('You must <a href="!login">login</a> or <a href="!register">register</a> to view this form.', array('!login' => $login, '!register' => $register));
      }
    }
    else {
      // The user must be some other role to submit.
      $message = t('You do not have permission to view this form.');
    }
  }

  // If the user has exceeded the limit of submissions, explain the limit.
  elseif ($user_limit_exceeded && !$cached) {
    if ($node->webform['submit_interval'] == -1 && $node->webform['submit_limit'] > 1) {
      $message = t('You have submitted this form the maximum number of times (@count).', array('@count' => $node->webform['submit_limit']));
    }
    elseif ($node->webform['submit_interval'] == -1 && $node->webform['submit_limit'] == 1) {
      $message = t('You have already submitted this form.');
    }
    else {
      $message = t('You may not submit another entry at this time.');
    }
    $type = 'error';
  }
  elseif ($total_limit_exceeded && !$cached) {
    if ($node->webform['total_submit_interval'] == -1 && $node->webform['total_submit_limit'] > 1) {
      $message = t('This form has received the maximum number of entries.');
    }
    else {
      $message = t('You may not submit another entry at this time.');
    }
  }

  // If the user has submitted before, give them a link to their submissions.
  if ($submission_count > 0 && $node->webform['submit_notice'] == 1 && !$cached) {
    if (empty($message)) {
      $message = t('You have already submitted this form.') . ' ' . t('<a href="!url">View your previous submissions</a>.', array('!url' => url('node/' . $node->nid . '/submissions')));
    }
    else {
      $message .= ' ' . t('<a href="!url">View your previous submissions</a>.', array('!url' => url('node/' . $node->nid . '/submissions')));
    }
  }

  if ($page && isset($message)) {
    drupal_set_message($message, $type, FALSE);
  }
}
