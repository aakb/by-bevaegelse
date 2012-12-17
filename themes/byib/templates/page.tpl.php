<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['branding']: Branding area.
 * - $page['header']:   Site navigation.
 * - $page['content']:  The main content of the current page.
 * - $page['footer']:   Fat footer.
 * - $page['bottom']:   Page bottom.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>

<header>

  <div class="grid-inner">

    <div class="header-inner">
      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

      <?php print render($page['header']); ?>
    </div>

    <?php print render($page['navigation']); ?>

  </div>

</header>

<?php if (!empty($page['content_top'])): ?>
  <?php print render($page['content_top']); ?>
<?php endif; ?>


<?php if (!empty($page['content']) ||
  !empty($page['secondary_content']) ||
  !empty($page['tertiary_content'])): ?>

  <article class="main-content">
    <div class="content-wrapper">

      <?php if (!empty($page['content'])): ?>
        <?php print render($page['content']); ?>
      <?php endif; ?>

      <?php if (!empty($page['secondary_content'])): ?>
        <?php print render($page['secondary_content']); ?>
      <?php endif; ?>

      <?php if (!empty($page['tertiary_content'])): ?>
        <?php print render($page['tertiary_content']); ?>
      <?php endif; ?>

      <?php if (!empty($page['attachment_first']) ||
        !empty($page['attachment_second']) ||
        !empty($page['attachment_third']) ||
        !empty($page['attachment_fourth'])): ?>

      <div class="attachments-wrapper">

        <?php if (!empty($page['attachment_first'])): ?>
          <?php print render($page['attachment_first']); ?>
        <?php endif; ?>

        <?php if (!empty($page['attachment_second'])): ?>
          <?php print render($page['attachment_second']); ?>
        <?php endif; ?>

        <?php if (!empty($page['attachment_third'])): ?>
          <?php print render($page['attachment_third']); ?>
        <?php endif; ?>

        <?php if (!empty($page['attachment_fourth'])): ?>
          <?php print render($page['attachment_fourth']); ?>
        <?php endif; ?>

      </div>
      
    <?php endif; ?>

    </div>
  </article>

<?php endif; ?>

<?php if (!empty($page['footer'])): ?>
  <footer class="grid-full">
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>

<?php if (!empty($page['bottom'])): ?>
  <div class="grid-full bottom">
    <?php print render($page['bottom']); ?>
  </div>
<?php endif; ?>