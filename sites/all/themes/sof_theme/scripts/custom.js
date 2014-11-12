(function($) {
  /**
  * Header Scripts 
  */	
  Drupal.behaviors.sofHeader = {
    attach: function (context, settings) {
    			
		/*//Hide navigation on click on body if naviagation container is visible
         if($('.header-inner-navigation-container:visible').length == 0){	
          $(document).on('click touchstart', 'html',function () {       
	        	$(".header-inner-navigation-container").hide();
			    $('#nav-activation-link span').removeClass("active");
				$('.header-navigation-container').removeClass("active");
	         }); 	  
		}
		
        //Stop propagating for links of the navigation
        $(document).on('click touchstart', '.header-inner-navigation-container',function (e) {
			e.stopPropagation();
		});*/
		 
		//Show / Hide navigation script	for submenu
         var tOut = null; 
	     $(document).on('mouseenter touchstart','#block-system-main-menu .menu > li',function(e){
	     	e.stopPropagation();
	     	 e.preventDefault();
	     	var $this=$(this);
	     	tOut=  setTimeout(function () { //Here
	     		$this.addClass("slideul"),
		        $this.find('.second-level-main-container').addClass("active")
		    }, 500);	        	
         }).on('mouseleave touchend','#block-system-main-menu .menu > li',function(e){
	     	$(this).removeClass("slideul");
        	$(this).find('.second-level-main-container').removeClass("active");
         });  			
	     
         
         
			
	     
		//Show / Hide navigation script on medium and small
		$('#nav-activation-link span').click(function(e){
			e.stopPropagation();
			$('.header-inner-navigation-container').stop().toggle();
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