(function ($) {
  Drupal.behaviors.formillaChat = {
    attach: function (context, settings) {
      // Formilla chatbot.
      var head = document.getElementsByTagName("head").item(0);
      var script = document.createElement("script");

      var src = (document.location.protocol == 'https:'
        ? 'https://www.formilla.com/scripts/feedback.js'
        : 'http://www.formilla.com/scripts/feedback.js');

      script.setAttribute("type", "text/javascript");
      script.setAttribute("src", src);
      script.setAttribute("async", true);

      var complete = false;

      script.onload = script.onreadystatechange = function () {
        if (!complete && (!this.readyState
          || this.readyState == 'loaded'
          || this.readyState == 'complete')) {
          complete = true;
          Formilla.guid = 'csd781de-4a73-4437-9e34-21236a2a2175';
          Formilla.loadWidgets();
        }
      };

      head.appendChild(script);
    }
  };
})(jQuery);
