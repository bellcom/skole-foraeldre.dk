// <?php
/**
 * @file
 * Java Script file for custom made scripts.
 */
// ?>
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
	  if( /Android|webOS|iPhone|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent) ) {  	
        function close_accordion_section() {
	      $('#block-system-main-menu .menu > li').find('a').removeClass('active');
		  $('#block-system-main-menu .menu > li').removeClass('slideul');
		  $('#block-system-main-menu .menu > li').find('.second-level-main-container').stop(true, true).removeClass("active");
        }
        //Remove class by default 
	    $('#block-system-main-menu .menu > li').find('a').removeClass('active');
	      //Run script on click
		  $('#block-system-main-menu .menu > li').click(function(e) {
		    if($(e.target).is('.active')) {
		      close_accordion_section();
		    }else {
		      close_accordion_section();
		      $(this).find('a').addClass('active');
		      $(this).addClass('slideul');
		      $(this).find('.second-level-main-container').stop(true, true).addClass("active");
		    }
		  });
      }
      else {
	    var navTimers = [];
	    $("#block-system-main-menu .menu > li").live('mouseenter',function() {
	      var id = jQuery.data( this );
	      var $this=$(this);
	      navTimers[id] = setTimeout( function() {
	        $this.addClass("slideul");  
	        $this.find('a').addClass('active');
	        $this.find('.second-level-main-container').stop(true, true).addClass("active");
	          navTimers[id] = "";
	        }, 500 );
	     }).live('mouseleave',function() {
	       var id = jQuery.data( this );
	       if ( navTimers[id] != "" ) {
	         clearTimeout( navTimers[id] );
	       }
	       else {
	         $(this).find('.second-level-main-container').removeClass("active");
	         $(this).removeClass("slideul");
	         $(this).find('a').removeClass('active');
	       }
	    });
      }
      
      //Hide navigation on click on body if naviagation container is visible
      if($('.header-inner-navigation-container:visible').length == 0) {
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
      	$("#block-system-main-menu .menu > li a").removeClass('active');
        $('.header-inner-navigation-container').stop().toggle();
        $('#nav-activation-link span').toggleClass("active");
        $('.header-navigation-container').toggleClass("active");
      });
    
    }
  };
  
  /**
  *  General Scripts
  */
  Drupal.behaviors.sofGeneralScripts = {
    attach: function (context, settings) {

      // Position of flexslider navigation arrows
      function SliderNavigationposition() {
        var heightSlideimg = $('.flexslider .slides img').height();
        $('.left-article-region .flex-direction-nav').css('top',heightSlideimg/2);
      }

      // Position of flexslider navigation arrows call functions
      $(window).load(SliderNavigationposition);
      $(window).resize(SliderNavigationposition);

      //Remove link from last navigation level
      $("#block-system-main-menu li.expanded > a").removeAttr("href");

      //Mailchimp add focus
      $('.news-deck-newsletter').bind('click', function(event) {
        event.preventDefault();
        $('.mailchimp-newsletter-mergefields input').focus();
        $(window).scrollTop($('#mailchimp-newsletter-503817-mergefields').offset().top);
      });

      //Mailchimp form changes
      $('input[name$="mergevars[EMAIL]"]').attr('placeholder', 'example@domain.dk');
      $('.mailchimp-signup-subscribe-form div[style*="block"]').addClass('thanks-message-mailchimp').css('padding-top','25px');
      $(".thanks-message-mailchimp" ).prepend($( "<span class='thank-icon'></span>" ));
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
    }
  };

  /**
  * Wrapping Scripts
  */
  Drupal.behaviors.sofWrapping = {
    attach: function (context, settings) {	
      //Intro Deck wrappers
      $('.pane-bundle-intro-deck-pane', context).each(function(){
        $('.field-name-field-teaser', this).next('.field-name-field-single-link').andSelf().wrapAll('<div class="intro-deck-group-first"></div>');
        $('.field-name-field-link-group-title-first', this).next('.field-name-field-five-links-first').andSelf().wrapAll('<div class="intro-deck-group"></div>');
        $('.field-name-field-link-group-title-second', this).next('.field-name-field-five-links-second').andSelf().wrapAll('<div class="intro-deck-group"></div>');
      });
		
      //Magazine Deck               	
      $(".pane-bundle-magazine-pane", context).each(function(){
      	$(".fieldable-panels-pane .field-name-field-magazine-category, .fieldable-panels-pane .field-name-field-magazine-links", this).wrapAll('<div class="mag-deck-right-group"></div>');
      });
      
      //What we write about deck               	
      $(".field-name-field-we-recommend-reference .field-item", context).each(function(){
      	$(".node-title-werecommend", this).wrap('<div class="write-about-title-wrap"></div>');
      });

      //Apache Solr Search edit form
      $(".search-form #edit-submit, #apachesolr-panels-search-form #edit-actions" ).wrap( "<div class='new-search-wrapper'></div>");
      $(".sof_toolbox_wrapper #edit-search-field" ).wrap( "<div class='toolbox-search-wrapper'></div>");

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
