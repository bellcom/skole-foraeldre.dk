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
          pointer = $(this);
	      navTimers[id] = setTimeout( function() {
            $("#block-system-main-menu .menu > li").removeClass('slideul');
            $("#block-system-main-menu .menu > li a").removeClass('active');
            $('.second-level-main-container').removeClass("active");
            pointer.addClass("slideul");
            pointer.find('a').addClass('active');
            pointer.find('.second-level-main-container').stop(true, true).addClass("active");
	          navTimers[id] = "";
	        }, 500 );
	     }).live('mouseleave',function() {
          pointer = $(this);
          console.log(pointer);
	       var id = jQuery.data( this );
	       if ( navTimers[id] != "" ) {
	         clearTimeout( navTimers[id] );
	       }
	       else {
             setTimeout(function(){
               if(!$('.second-level-main-container').hasClass('over')) {
                 pointer.find('.second-level-main-container').removeClass("active");
                 pointer.removeClass("slideul");
                 pointer.find('a').removeClass('active');
               }else {
                 NavigationMenu();
               }
             },500);
	       }
	    });

        $('.second-level-main-container').live('mouseenter',function() {
          $(this).addClass('over');
        }).live('mouseleave',function() {
          $(this).removeClass('over');
        });

        function NavigationMenu () {
          $('.second-level-main-container').live('mouseleave',function() {
            pointer = $(this);
              setTimeout(function(){
                pointer.removeClass('active');
              },1000);
          });
        }
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
        var heightSlideimg = $('.flexslider li img').height();
        var MainheightSlideimg = $('.flexslider li a').height();
        if($('.slide-background:visible').length != 0) {
          $('.flex-direction-nav').css("display", "block").css('top',MainheightSlideimg/2);
        }else
        $('.flex-direction-nav').css("display", "block").css('top',heightSlideimg/2);
      }

      // Position of flexslider navigation arrows call functions
      window.onload = function() {
        var heightSlideimg = $('.flexslider li img').height();
        var MainheightSlideimg = $('.flexslider li a').height();
        if($('.slide-background:visible').length != 0) {
          $('.flex-direction-nav').css("display", "block").css('top',MainheightSlideimg/2);
        }else
        $('.flex-direction-nav').css("display", "block").css('top',heightSlideimg/2);
      }
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
      $('.field-name-field-we-recommend .field-label, .field-name-field-related-terms h2, #node_article_full_group_bottomaregion .field-name-field-link h2, ').each(
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
      //Also see deck wrap every three elements in one
      var $span = $(".field-name-field-related-article-news .field-item").not('article .field-item');
      for (var i = 0; i < $span.length; i += 3) {
        var $div = $("<div/>", {
          class: 'recomendation-public'
        });
        $span.slice(i, i + 3).wrapAll($div);
      }
      //Submited by changes to html structure
      $("body.logged-in .left-article-region .pane-node-updated").parent().parent().addClass('pane-node-updated');
      $("body.logged-in .left-article-region .pane-node-author").parent().parent().addClass('pane-node-author');
      $("body.logged-in .panels-ipe-portlet-marker.pane-node-updated, body.logged-in .panels-ipe-portlet-marker.pane-node-author").wrapAll('<div class="submitedby-main-container"></div>');
      $("body.not-logged-in .pane-node-updated, body.not-logged-in .pane-node-author").wrapAll('<div class="submitedby-main-container"></div>');
      //Read More Block changes to html structure
      $("body.logged-in .bottom-article-region .pane-read-also-read-also-pane").parent().parent().addClass('read-more-inline-container');
      $("body.logged-in .bottom-article-region .pane-node-field-link").parent().parent().addClass('relared-topics-inline-container');
      $("body.logged-in .read-more-inline-container, body.logged-in .relared-topics-inline-container").wrapAll('<div class="read-more-main-container"><div class="read-more-main-container-inline"></div></div>');
      $("body.not-logged-in .pane-read-also-read-also-pane, body.not-logged-in .pane-node-field-link").wrapAll('<div class="read-more-main-container"><div class="read-more-main-container-inline"></div></div>');
   }
  };
})(jQuery);
