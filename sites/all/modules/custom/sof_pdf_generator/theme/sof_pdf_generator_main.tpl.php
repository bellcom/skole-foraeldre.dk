<?php

/**
 * @file
 * Theme implementation SOF pdf generator. This html will be converted to pdf file
 * 
 * Variables:
 * - $css:  An array of CSS files for the current page.
 * - $js:   An array of CSS files for the current page.
 * - $page: The rendered page content.
 */

?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" version="XHTML+RDFa 1.0" >
  <head>
    <?php print $css; ?>
    <?php print $js; ?>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  </head>
  <body>
    
    <?php print $page; ?>
    
  </body>
</html>
