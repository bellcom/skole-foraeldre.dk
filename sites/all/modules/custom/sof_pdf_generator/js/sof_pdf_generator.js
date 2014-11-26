(function($) {

    Drupal.behaviors.sof_pdf_generator = {

        attach : function(context, settings) {

            //Split the body content in two columns
            if (typeof Drupal.settings.sof_pdf_generator !== 'undefined') {
                $('.sof-column-content', context).columnize({
                    columns : 2
                });
            }

            //Add clases to download links
            $('a[href*="sof-pdf-generate"]', context).addClass('sof-pdf-generate-inline-link');

        }
    };

})(jQuery);
