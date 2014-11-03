(function($) {
  /**
  * Header Scripts 
  */	
  Drupal.behaviors.sofHeader = {
    attach: function (context, settings) {   
	
		//Show / Hide navigation script
		$(".first-level li").hover(function(){
			$(this).delay(400).toggleClass("slideul");
			var slideul = $(this).hasClass("slideul") ? true : false;
			if(slideul){
				$(this).find('.second-level-main-container').stop(true, true).delay(400).slideDown();
			}else{
				$(this).find('.second-level-main-container').slideUp();
			}
		});	
		
		//Show / Hide navigation script
		$(".first-level li").click(function(){
			$(this).toggleClass("slideul");
			var slideul = $(this).hasClass("slideul") ? true : false;
			if(slideul){
				$(this).find('.second-level-main-container').delay(800).stop(true, true).show();
			}else{
				$(this).find('.second-level-main-container').delay(1000).hide();
			}
		});		
                
		//Show / Hide navigation script on medium and small
		$('#nav-activation-link span').click(function(e){
			e.preventDefault();
			$('.header-inner-navigation-container').stop().slideToggle('fast');
			$('#nav-activation-link span').toggleClass("active");
			$('.header-navigation-container').toggleClass("active");
		});	
                     	
   }
  };
  
  /**
  * Wrapping Scripts 
  */	
  Drupal.behaviors.sofWrapping = {
    attach: function (context, settings) {   
	
	  //Intro Deck
      $(".pane-bundle-intro-deck-pane .field-name-field-teaser, .pane-bundle-intro-deck-pane .field-name-field-single-link").wrapAll('<div class="intro-deck-group-first"></div>');
      $(".pane-bundle-intro-deck-pane .field-name-field-link-group-title-first, .pane-bundle-intro-deck-pane .field-name-field-five-links-first").wrapAll('<div class="intro-deck-group"></div>');
      $(".pane-bundle-intro-deck-pane .field-name-field-link-group-title-second, .pane-bundle-intro-deck-pane .field-name-field-five-links-second").wrapAll('<div class="intro-deck-group"></div>');
      
      //Magazine Deck               	
      $(".field-name-field-magazine-category, .field-name-field-magazine-links").wrapAll('<div class="mag-deck-right-group"></div>');
   }
  };


})(jQuery);