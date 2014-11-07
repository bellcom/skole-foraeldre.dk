<?php

/**
 * Class WkHtmlToPdf used as a wrapper class tp \mikehaertl\wkhtmlto\Pdf for backward compatibility.
 */
class WkHtmlToPdf extends \mikehaertl\wkhtmlto\Pdf {

  /**
   * Constructor that passes the $options to the parent constructor.
   * @param null $options
   */
  function __construct($options = null) {
    parent::__construct($options);
  }
}
