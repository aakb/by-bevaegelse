//https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/String/repeat
if (!String.prototype.repeat) {
  String.prototype.repeat = function(count) {
    'use strict';
    if (this == null) {
      throw new TypeError('can\'t convert ' + this + ' to object');
    }
    var str = '' + this;
    count = +count;
    if (count != count) {
      count = 0;
    }
    if (count < 0) {
      throw new RangeError('repeat count must be non-negative');
    }
    if (count == Infinity) {
      throw new RangeError('repeat count must be less than infinity');
    }
    count = Math.floor(count);
    if (str.length == 0 || count == 0) {
      return '';
    }
    // Ensuring count is a 31-bit integer allows us to heavily optimize the
    // main part. But anyway, most current (August 2014) browsers can't handle
    // strings 1 << 28 chars or longer, so:
    if (str.length * count >= 1 << 28) {
      throw new RangeError('repeat count must not overflow maximum string size');
    }
    var rpt = '';
    for (;;) {
      if ((count & 1) == 1) {
        rpt += str;
      }
      count >>>= 1;
      if (count == 0) {
        break;
      }
      str += str;
    }
    return rpt;
  }
}

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
          height: 'toggle'
        }, {
          duration: 250
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
          var sub = "-".repeat($(this).parents('li').length);

          $("<option />", {
            "value" : $(this).attr("href"),
            "text": sub + $(this).text()
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
