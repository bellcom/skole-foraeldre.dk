<?php

/*
 * @file
 *
 * @author Martina Radeva <martina@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

?>

(function($) {
  Drupal.behaviors.sofGeneralTweaksCommerce = {
    attach: function(context, settings) {
      if (settings.sofGeneralTweaksCommerce) {
        var cart = settings.sofGeneralTweaksCommerce;
        $('.sof-commerce-quantity').change(function() {
          var quantity = $(this).find(':input').val(),
          id = $(this).find(':input').attr('id'),
          dq = $(this).find(':input').attr('defaultValue'),
          splitId = id.split('-'),

          key = splitId[3];
          if (quantity < cart[key]) {
            $(this).find(':input').val(dq);
            alert(Drupal.t('The minimal product quantity is:' + ' ' + cart[key]));
          }
        });
      }
    }
  };
})(jQuery)
