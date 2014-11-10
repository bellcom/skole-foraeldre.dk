(function($) {
  /**
  * Header Scripts 
  */	
  Drupal.behaviors.sofHeader = {
    attach: function (context, settings) {
    		
		//Show / Hide navigation script
		//$("#block-system-main-menu .menu li").hover(function(){
			//$(this).delay(400).toggleClass("slideul");
			//var slideul = $(this).hasClass("slideul") ? true : false;
			//if(slideul){
				//$(this).find('.second-level-main-container').stop(true, true).delay(400).show();
			//}else{
				//$(this).find('.second-level-main-container').hide();
			//}
		//});
		
		//Show / Hide navigation script
		$("#block-system-main-menu .menu li").hover(function(){
			$(this).delay(400).toggleClass("slideul");
			var slideul = $(this).hasClass("slideul") ? true : false;
			if(slideul){
				$(this).find('.second-level-main-container').stop(true, true).delay(400).show();
			}else{
				$(this).find('.second-level-main-container').hide();
			}
		});
			
		if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent) ){
			//Show / Hide navigation script on iphones
			$("#block-system-main-menu .menu li").click(function(){
				$(this).delay(400).toggleClass("slideul");
				var slideul = $(this).hasClass("slideul") ? true : false;
				if(slideul){
					$(this).find('.second-level-main-container').stop(true, true).delay(400).slideDown();
				}else{
					$(this).find('.second-level-main-container').slideUp();
				}
			});		
		}	
                
		//Show / Hide navigation script on medium and small
		$('#nav-activation-link span').click(function(e){
			e.preventDefault();
			$('.header-inner-navigation-container').stop().slideToggle();
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
	
	 $("#block-system-main-menu li.expanded > a").removeAttr("href");
	
	  //Intro Deck
      $(".pane-bundle-intro-deck-pane .field-name-field-teaser, .pane-bundle-intro-deck-pane .field-name-field-single-link").wrapAll('<div class="intro-deck-group-first"></div>');
      $(".pane-bundle-intro-deck-pane .field-name-field-link-group-title-first, .pane-bundle-intro-deck-pane .field-name-field-five-links-first").wrapAll('<div class="intro-deck-group"></div>');
      $(".pane-bundle-intro-deck-pane .field-name-field-link-group-title-second, .pane-bundle-intro-deck-pane .field-name-field-five-links-second").wrapAll('<div class="intro-deck-group"></div>');
      
      //Magazine Deck               	
      $(".fieldable-panels-pane .field-name-field-magazine-category, .fieldable-panels-pane .field-name-field-magazine-links").wrapAll('<div class="mag-deck-right-group"></div>');
   
   		
      //Recomended item deck, wrapp 10 elements in one
      var $span = $(".view-id-recommended_items_overview .views-row");
	  for (var i = 0; i < $span.length; i += 10) {
		    var $div = $("<div/>", {
		        class: 'recomendation-overview'
		    });
		    $span.slice(i, i + 10).wrapAll($div);
      }
      
      var $span = $(".view-other-releases .views-row");
	  for (var i = 0; i < $span.length; i += 2) {
		    var $div = $("<div/>", {
		        class: 'recomendation-public'
		    });
		    $span.slice(i, i + 2).wrapAll($div);
      }
               
	  //Remove colons from field label 
	  $('.field-name-field-we-recommend .field-label').each(
	        function() {
	          var myText = $(this);
	          myText.text( myText.text().replace(':','') );
	        }
       );   
   }
  };


})(jQuery);