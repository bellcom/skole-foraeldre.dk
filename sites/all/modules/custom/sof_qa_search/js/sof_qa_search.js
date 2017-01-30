/**
 * @file
 * Search through the Q&A page
 */

(function($) {
    Drupal.behaviors.sof_qa_search = {
        attach: function (context, settings) {
            //ignore enter key
            $('#live-search').keypress(function(e) {
               if (e.which ==  13) {
                   e.preventDefault();
               }
            });
            //search function
            $('#live-search').on('input', function () {

                var searchInput = $(this);
                if(searchInput.val().length === 0){

                    collapsAllFieldets();
                } else {
                    collapsAllFieldets();

                    var serchedItem = new RegExp($(this).val(), 'igm');
                    var matchArr = [];
                    $('.view-question-view .field-content').each(function () {
                        var question = $(this);
                        var questionText = question.text();
                        if (questionText.match(serchedItem)) {
                           matchArr.push(question);
                        }
                    });
                    if(matchArr.length > 0) {
                        $.each(matchArr, function (index, value) {
                            var element = matchArr[index];
                            element.parents('fieldset').removeClass('collapsed');
                        })
                    }
                }
            });
            function collapsAllFieldets() {
                $('.view-qa-taxonomy-view fieldset.views-row').each(function () {
                    if(!$(this).hasClass('collapsed'))
                        $(this).addClass('collapsed');
                });
            }

            //expand specific content based on url#
            var link = window.location.href;
            if (link.includes("#")) {
                var hash = link.substring(link.indexOf("#")+1);

                $('.view-qa-taxonomy-view .field-content').each(function(index) {
                   if ($(this).hasClass('qa-answer-'+hash)) {
                       var field = $(this);
                       field.parents('fieldset').removeClass('collapsed');
                       $('html, body').animate({
                           scrollTop: field.offset().top -30
                       }, 1000);
                   }
                });
            }
        }
    }
})(jQuery);