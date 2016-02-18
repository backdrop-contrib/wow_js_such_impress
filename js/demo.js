/**
 * @file
 * JS for demo for wow_js_such_impress module
 */
(function($, Backdrop, window, document, undefined) {

  $(document).ready(function() {

    // run Javascript on page load here
$(".block").addClass("wow");
$(".block").addClass("bounceInUp");
wow = new WOW(
                      {
                      boxClass:     'wow',      // default
                      animateClass: 'animated', // default
                      offset:       0,          // default
                      mobile:       false,
                      live:         true        // default
                    }
                    )
                    wow.init();
  });
})(jQuery, Backdrop, this, this.document);
