(function() {
  document.addEventListener('DOMContentLoaded', function(event) {
    var delay = 1; // In seconds.
    var popup = document.querySelector('.bean-popup');
    var body = document.querySelector('body');

    // The popup does not exist. Abort!
    if (popup === null) {
      return;
    }

    // Open popup after 5 sec.
    setTimeout(function() {
      body.classList.add('bean-popup--visible');
    }, (delay * 1000));

    // Don't close on click inside the content area.
    var content = popup.querySelector('.bean-popup__content');
    document.addEventListener('click', function(event) {
      var isClickInside = content.contains(event.target);

      if (!isClickInside) {
        body.classList.remove('bean-popup--visible');
      }
    });
  });
})();
