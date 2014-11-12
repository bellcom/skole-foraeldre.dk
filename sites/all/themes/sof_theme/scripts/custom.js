(function($) {
  /**
  * Header Scripts 
  */	
  Drupal.behaviors.sofHeader = {
    attach: function (context, settings) {
	
		//Show / Hide navigation script	for submenu 	
        /* $("#block-system-main-menu .menu > li").hover(function(e){
			     $(this).toggleClass("slideul");
				 var slideul = $(this).hasClass("slideul") ? true : false;
				 if(slideul){
				  $(this).find('.second-level-main-container').delay(5000).addClass("active");
				 }else{
				  $(this).find('.second-level-main-container').removeClass("active");
				}
			});*/

         var tOut = null; 
	     $(document).on('mouseenter touchstart','#block-system-main-menu .menu > li',function(e){
	     	e.preventDefault();
	     	var $this=$(this);
	     	tOut=  setTimeout(function () {
	     		$this.addClass("slideul");
		        $this.find('.second-level-main-container').addClass("active");
		   }, 500);       	
         }); 
         $(document).on('mouseleave touchend','#block-system-main-menu .menu > li',function(e){
	     	var $this = $(this);
        	$this.find('.second-level-main-container').removeClass("active");
        	$this.removeClass("slideul");
         }); 		
     
		//Show / Hide navigation script on medium and small
		$('#nav-activation-link span').click(function(e){
			e.stopPropagation();
			$('.header-inner-navigation-container').stop().toggle();
			$('#nav-activation-link span').toggleClass("active");
			$('.header-navigation-container').toggleClass("active");
		});
		//Show / Hide navigation script on medium and small
		$('#nav-activation-link span').click(function(e){
			e.stopPropagation();
			$('.header-inner-navigation-container').stop().toggle();
			$('#nav-activation-link span').toggleClass("active");
			$('.header-navigation-container').toggleClass("active");
		});
		
		/*//Hide navigation on click on body if naviagation container is visible
         if($('.header-inner-navigation-container:visible').length == 0){	         
		     $("html").click(function(){
	        	 $(".header-inner-navigation-container").hide();
			    $('#nav-activation-link span').removeClass("active");
				$('.header-navigation-container').removeClass("active");
	         }); 	  
		} */
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