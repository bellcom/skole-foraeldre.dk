/* 
 * @file
 */
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
                       key = splitId[3];console.log(dq);
                   if (quantity < cart[key]) {
                       $(this).find(':input').val(dq);
                       alert(Drupal.t('Minimal quantity of teh prduct is ' + cart[key]));
                   }
                });
            }
        }
    };
})(jQuery)
