(function ($) {

  Drupal.behaviors.sofPdfColumnizer = {
    
    attach: function (context, settings) {
    	
    	//Split the body content in two columns
    	$('.sof-column-content', context).columnize({ columns: 2 });	    
    }
    
  };  
})(jQuery);