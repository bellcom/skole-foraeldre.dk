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

		
                                     	
   }
  };
 

})(jQuery);