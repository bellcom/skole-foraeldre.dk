(function() {
  function getCookie(name) {
    var v = document.cookie.match('(^|;) ?' + name + '=([^;]*)(;|$)');

    return v ? v[2] : null;
  }
  function setCookie(name, value, days) {
    if (days) {
      var d = new Date;

      d.setTime(d.getTime() + 24*60*60*1000*days);

      document.cookie = name + "=" + value + ";path=/;expires=" + d.toGMTString();
    }
    else {
      document.cookie = name + "=" + value + ";path=/;";
    }
  }
  function deleteCookie(name) {
    setCookie(name, '', -1);
  }

  document.addEventListener('DOMContentLoaded', function(event) {
    var delay = 1; // In seconds.
    var popup = document.querySelector('.bean-popup');
    var body = document.querySelector('body');
    var popupIsSeen = getCookie('popupIsSeen');

    if (popupIsSeen === 'yes') {
      return;
    }

    // The popup does not exist. Abort!
    if (popup === null) {
      return;
    }

    // Open popup after X sec.
    setTimeout(function() {
      body.classList.add('bean-popup--visible');

      setCookie('popupIsSeen', 'yes');
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
