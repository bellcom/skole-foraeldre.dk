/**
 * @file
 * SOF pdf generator behaviours
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

(function($) {
  Drupal.behaviors.sof_pdf_generator = {
    attach : function(context, settings) {
      // Create pdf pages from content.
      if (typeof Drupal.settings.sof_pdf_generator !== 'undefined') {
        // Setup global splitting rules.
        $('.sof-pdf-content').find('table, thead, tbody, tfoot, colgroup, caption, label, legend, script, style, textarea, button, object, embed, tr, th, td, li, h1, h2, h3, h4, h5, h6, form').addClass('dontsplit');
        $('.sof-pdf-content').find('h1, h2, h3, h4, h5, h6').addClass('dontend');
        $('.sof-pdf-content').find('br').addClass('removeiflast').addClass('removeiffirst');

        $nodeObj = $('#sof-pdf-contents', context);

        // Node header Image+teaser.
        $initialContent = $('header', $nodeObj);

        // Initial content height.
        var imgTeaserHeight = $initialContent.outerHeight(true), initialContentHeight = 0;

        // Image dimensins bug fix.
        if ($initialContent.find('div.sof-pdf-top-image').length) {
          imgTeaserHeight += 396;
        }
        else {
          imgTeaserHeight += 2;
        }

        if (initialContentHeight <= imgTeaserHeight) {
          initialContentHeight = 815 - imgTeaserHeight;
        }
        else {
          initialContentHeight = 815 - ( imgTeaserHeight % 815);
        }

        // Prevent blank page.
        if (initialContentHeight == 0) {
          initialContentHeight = 815;
        }

        // Build pages.
        buildPage($initialContent, initialContentHeight);
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
    contentHeight = typeof contentHeight !== 'undefined' ? contentHeight : 815;
    if ($('#sof-pdf-contents').contents().length > 0) {
      // Initial page.
      $page = $(".sof-pdf-page-template:first").clone().addClass("sof-pdf-page").css({
        display: "block",
        height: 815
      });

      // Set page contents height.
      $page.find('.content').css({
        display: "block",
        height: contentHeight
      });

      // Add header+image.
      if ($initialContent) {
        $page.prepend($initialContent);
      }

      $(".sof-pdf-all-content").append($page);
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
    }
  }
})(jQuery);
