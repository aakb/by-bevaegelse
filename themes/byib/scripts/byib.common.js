(function ($) {

  /**
   * Add markup for main menu toggle.
   */
  function addToggleMainMenu(element, destination) {

    // Create wrapper for mobile menu.
    $("<div />", {
      "class" : "js-toggle-main-menu"
    }).appendTo($(destination));

    // Add span with text
    $("<span />", {
      "class" : "block-title",
      "text"  : Drupal.t('Menu')
    }).appendTo($(element));

    // Toggle on click
    $(element).click(function () {
      $(".main-menu").animate({
        top: '=-90px',
        height: 'toggle'
      });
    });
  }

  /**
   * Defines function().
   * Creates <select /> from menu block.
   */
  function menuToSelect(source, destination) {

    // Make sure there is a reason to create the menu.
    if ($(source).length) {
      // Create wrapper for mobile menu.
      $("<div />", {
        "class" : "mobile-menu"
      }).appendTo(destination);

      // Create menu-title
      $("<h2 />", {
        "class" : "block-title",
        "text"  : Drupal.t('Navigation')
      }).appendTo(".mobile-menu", $(destination));

      // Create the dropdown base
      $("<select />", {
      }).appendTo(".mobile-menu", $(destination));

      // Create default option "Select page..."
      $("<option />", {
         "selected": "selected",
         "value"   : "",
         "text"    : Drupal.t('Select page')
      }).appendTo($("select", destination));

      // Populate dropdown with menu items
      $(source).each(function() {

        var el = $(this);
        var children = el.find("li");
        var blockTitle = el.find(".block-title > a");

        if (blockTitle.length != 0) {
          $("<option />", {
            "value" : blockTitle.attr("href"),
            "text"  : blockTitle.text()
          }).appendTo("select:last");
        }

        children.find("a").each(function() {
          $("<option />", {
            "value" : $(this).attr("href"),
            "text": " - " + $(this).text()
          }).appendTo("select:last");
        });

      });

      // To make dropdown actually work
      $("select", destination).change(function() {
        window.location = $(this).find("option:selected").val();
      });
    }
  }

  /**
   * Run functions on document ready.
   */

  $(document).ready(function() {
    addToggleMainMenu(".js-toggle-main-menu", "header");
  });

  $(document).ready(function() {
    menuToSelect(".secondary-content", "header");
  });

})(jQuery);
