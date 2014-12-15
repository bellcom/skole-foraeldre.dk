(function($) {
	
   //Extend support jquery for placeholder
   $.support.placeholder = (function(){
	    var i = document.createElement('input');
	    return 'placeholder' in i;
   })();
   $(document).ready( function(){ 
		  if(!$.support.placeholder){
		    $("input").each(function(){
		      if($(this).val()=="" && $(this).attr("placeholder") != ""){
		        $(this).val( $(this).attr("placeholder") );
		        
		        $(this).focus(function(){
		          if( $(this).val()==$(this).attr("placeholder") ) 
		          	$(this).val("");
		        });
		        
		        $(this).blur(function(){
		          if( $(this).val()=="" ) 
		          	$(this).val( $(this).attr("placeholder") );
		        });
		      }
		    });
		  }
	});
  /**
  * Header Scripts 
  */
  Drupal.behaviors.sofHeader = {
    attach: function (context, settings) {
    	
		   //Show Hide navigation script	for submenu 	
		   var navTimers = [];
		   $('#block-system-main-menu .menu > li').live('mouseenter', function() {
		   	    var id = jQuery.data( this );
		   	    var $this=$(this);
	     		navTimers[id] = setTimeout( function() {
					$this.addClass("slideul");
					$this.find('.second-level-main-container').stop(true, true).addClass("active");
					navTimers[id] = "";
				}, 500 );
			});
			//Hide navigation script	for submenu 	
			$('#block-system-main-menu .menu > li').live('mouseleave', function() { 
	    	     var id = jQuery.data( this );
				 if ( navTimers[id] != "" ) {
					 clearTimeout( navTimers[id] );
				 } else {
					 $(this).find('.second-level-main-container').removeClass("active");
	    	    	 $(this).removeClass("slideul");
				 }    
			});	
			$('.second-level-main-container').live('mouseenter', function() {
				$(this).addClass("active");
			});
		
         //Hide navigation on click on body if naviagation container is visible
         if($('.header-inner-navigation-container:visible').length == 0){
         	$('html').live('click touchstart', function() {	         
	        	$(".header-inner-navigation-container").hide();
			    $('#nav-activation-link span').removeClass("active");
				$('.header-navigation-container').removeClass("active");
	         }); 	  
		 }
		 //Stop propagating for links of the navigation
		 $('.header-right-main-container').live('click touchstart', function(e) {	
			e.stopPropagation();
		 });
         
	     //Show / Hide navigation script on medium and small
	      $('#nav-activation-link span').live('click', function(e) {
			$('.header-inner-navigation-container').stop().toggle();
			$('#nav-activation-link span').toggleClass("active");
			$('.header-navigation-container').toggleClass("active");
		 });
		 		 
   }
  };
  /**
  * Wrapping General Scripts
  */
  Drupal.behaviors.sofGeneralScripts = {
    attach: function (context, settings) {

		// Position of flexslider navigation arrows
		function SliderNavigationposition() {
		     var heightSlideimg = $('.flexslider .slides img').height();
	   		 $('.left-article-region .flex-direction-nav').css('top',heightSlideimg/2);	
		}
		
	    // Position of flexslider navigation arrows call functions
		$(document).ready(SliderNavigationposition);
		$(window).resize(SliderNavigationposition);
	
	    /*
	    //E-commerce dynamic height of title and description 	
	    function Ecommercetableheight() {
	    	//Title height
		    var heighttabledesc = $('tbody .views-field-field-sof-commerce-description').height();
			$('thead .views-field-field-sof-commerce-description').css('height',heighttabledesc+12);
			
			//Description height	
			var heighttabletitle = $('tbody .views-field-line-item-title').height();
			$('thead .views-field-line-item-title').css('height',heighttabletitle+14);
		}
			
		// E-commerce dynamic height of title and description call functions
		$(document).ready(Ecommercetableheight);
		$(window).resize(Ecommercetableheight);
		*/
	     //Remove link from last navigation level 
		 $("#block-system-main-menu li.expanded > a").removeAttr("href");
		 
      
	      //Mailchimp add focus
	   	  $('.news-deck-newsletter').bind('click', function(event){  
		 	 event.preventDefault();
		  	$('.mailchimp-newsletter-mergefields input').focus();    
		  	$(window).scrollTop($('#mailchimp-newsletter-503817-mergefields').offset().top);     
		  });
		  	
		  //Mailchimp form changes
	      $('input[name$="mergevars[EMAIL]"]').attr('placeholder', 'example@domain.dk');
	      $('.mailchimp-signup-subscribe-form div[style*="block"]').addClass('thanks-message-mailchimp').css('padding-top','25px');   
	      $( ".thanks-message-mailchimp" ).prepend( $( "<span class='thank-icon'></span>" ) );
	      if ($('#sof-general-tweaks-mailchimp .messages.error').length > 0) {
			$( ".thank-icon").css('display','none');
			$('.thanks-message-mailchimp').css('padding-top','0px');
		  } 
			 
		  //Remove colons from field label 
		  $('.field-name-field-we-recommend .field-label, #node_article_full_group_bottomaregion .field-name-field-link h2').each(
		        function() {
		          var myText = $(this);
		          myText.text( myText.text().replace(':','') );
		        }
	       ); 
	       //Download as pdf button 
	       $( ".publication-top-right-container .download-as-pdf" ).wrap( "<div class='download-as-pdf-out'></div>"); 
	       //E-commerce add to cart button
	       $( ".commerce-product-field-commerce-price , .field-name-field-sof-commerce-product" ).wrapAll( "<div class='publication-ecommercebutton'></div>" ); 	 
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
      $(".fieldable-panels-pane .field-name-field-magazine-category, .fieldable-panels-pane .field-name-field-magazine-links").wrapAll('<div class="mag-deck-right-group"></div>');
      
   	 //Apache Solr Search edit form
	 $( ".search-form #edit-submit, #apachesolr-panels-search-form #edit-actions" ).wrap( "<div class='new-search-wrapper'></div>" );
	 $( ".sof_toolbox_wrapper #edit-search-field" ).wrap( "<div class='toolbox-search-wrapper'></div>" );
	 
	 //Ecommerce tables 
	  $( "#views-form-commerce-cart-form-sof-default table, #edit-cart-contents,#commerce-checkout-form-review #edit-checkout-review" ).wrap( "<div class='table-main-container'></div>" );
      //Recomended item deck, wrapp 10 elements in one
      var $span = $(".view-id-recommended_items_overview .views-row");
	  for (var i = 0; i < $span.length; i += 10) {
		    var $div = $("<div/>", {
		        class: 'recomendation-overview'
		    });
		    $span.slice(i, i + 10).wrapAll($div);
      }
      
      //Publication listing page wrapp every 4 item in one 
      var $span = $(".view-other-releases .views-row , .view-publication-listing-view .views-row");
	  for (var i = 0; i < $span.length; i += 4) {
		    var $div = $("<div/>", {
		        class: 'recomendation-public'
		    });
		    $span.slice(i, i + 4).wrapAll($div);
      }
      
      //Publication listing page wrapp every 2 item in one 
      if ( $(window).width() < 920 && $(window).width() > 580 ) {
		  for (var i = 0; i < $span.length; i += 2) {
			    var $div = $("<div/>", {
			        class: 'recomendation-public'
			    });
			    $span.slice(i, i + 2).wrapAll($div);
	      }
      }

   }
  };


})(jQuery);