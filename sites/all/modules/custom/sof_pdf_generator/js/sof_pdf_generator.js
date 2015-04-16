/**
 * @file
 * SOF pdf generator behaviours
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

(function($) {
  // available page height in pixels
  var page_height_px = 815;

  Drupal.behaviors.sof_pdf_generator = {
    attach : function(context, settings) {
      // Create pdf pages from content.
      if (typeof Drupal.settings.sof_pdf_generator !== 'undefined') {
        // Setup global splitting rules.
        $('.sof-pdf-content').find('table, thead, tbody, tfoot, colgroup, caption, label, legend, script, style, textarea, button, object, embed, tr, th, td, li, h1, h2, h3, h4, h5, h6, form, blockquote').addClass('dontsplit');
        $('.sof-pdf-content').find('h1, h2, h3, h4, h5, h6').addClass('dontend');
        $('.sof-pdf-content').find('br').addClass('removeiflast').addClass('removeiffirst');

        var $nodeObj = $('#sof-pdf-contents', context);

        // Node header Image+teaser.
        var $initialContent = $('header', $nodeObj);

        // remove weird css rules // TODO: fix in css files directly
        $(".sof-pdf-all-content").css('float', 'none');
        $("body,html").css('height', 'auto');
        $("body,html").css('min-height', 'auto');

        // Wait for the document to fully load before building pages, so image dimensions can be checked.
        // Code is not cross-browser compatible, but it needs to work only in wkhtmltopdf (Webkit).
        var loaded=false, timer=setInterval(function() {
          if(!loaded && document.readyState=="complete") {
            loaded = true;
            clearInterval(timer);
            // Build pages.
            buildPage($initialContent, page_height_px);
          }
        }, 100);
      }

      // Add clases to download links.
      $('a[href*="sof-pdf-generate"]', context).addClass('sof-pdf-generate-inline-link');
    }
  };

  /**
   * Add columnized pages in beteen
   *   @param object|bool $initialContent
   *     Header object with title, teaser and optional image, FALSE if not first page
   *   @param int contentHeight
   *     calculated height for content on the first page
   *
   */
  function buildPage($initialContent, contentHeight) {
    // Check for default value.
    contentHeight = typeof contentHeight !== 'undefined' ? contentHeight : page_height_px;
    if ($('#sof-pdf-contents').contents().length > 0) {
      // Initial page.
      var $page = $(".sof-pdf-page-template:first").clone().addClass("sof-pdf-page").css({
        display: "block",
        height: page_height_px,
        
        // uncomment for debugging purposes, to see page element sizes
        //border:'1px solid black', boxSizing:'border-box', background:'#eeeeee',
        
        // the following makes each page div really start a separate page,
        // so setting a slightly lower than actual value for page_height_px is not a problem,
        // and setting a slightly higher than actual value will be more obvious
        'page-break-inside': 'avoid'
      });
      
      // Add header+image.
      if ($initialContent) {
        $page.prepend($initialContent);
      }

      $(".sof-pdf-all-content").append($page);
      
      // If given some initial content, we have less height remaining to work with
      contentHeight -= $page.find('.content').get(0).offsetTop;

      // Set page contents height.
      $page.find('.content').css({
        display: "block",
        height: contentHeight
      });
      
      // Call columnizer.
      $('#sof-pdf-contents').columnize({
        columns: 2,
        target: ".sof-pdf-page:last .content",
        overflow: {
          height: contentHeight,
          id: '#sof-pdf-contents',
          doneFunc: function() {
            buildPage(false);
          }
        }
      });
    }
    else {
      // Remove blank container from the top.
      $(".sof-pdf-page-template:first").remove();
      // Remove the container where the content was before columnizing it.
      $('.sof-pdf-content').remove();
    }
  }
})(jQuery);
