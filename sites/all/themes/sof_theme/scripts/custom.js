(function($) {

	
  /**
  * Header Scripts 
  */	
  Drupal.behaviors.sofHeader = {
    attach: function (context, settings) {      
		
		//Show / Hide navigation script
		$('#nav-activation-link span').click(function(e){
			e.preventDefault();
			$('.header-inner-navigation-container').stop().slideToggle('fast');
			$('#nav-activation-link span').toggleClass("active");
			$('.header-navigation-container').toggleClass("active");
		});	
		
		//Search page if no results
	    if($('.slides .field-content .item-list').length == 0){ 
			$('#block-views-related-articles-slider-block').hide();
	    };
                                     	
   }
  };
 

})(jQuery);