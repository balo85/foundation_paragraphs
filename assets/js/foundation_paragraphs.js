(function ($) {

  'use strict';

  Drupal.behaviors.foundationParagraphs = {
    attach: function (context) {
      $('body', context).once('foundationParagraphs').each(function () {
      });
    }
  };

})(jQuery);
