<?php

/**
 * @file
 * Theme implementation SOF pdf generator. This html will be converted to pdf file
 *
 * Variables:
 * - $css:  An array of CSS files for the current page.
 * - $js:   An array of CSS files for the current page.
 * - $page: The rendered page content.
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

?>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" version="XHTML+RDFa 1.0" >
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=UTF-8" />
    <?php print $css; ?>
    <?php print $js; ?>
  </head>
  <body>
    <?php print $page; ?>
  </body>
</html>
