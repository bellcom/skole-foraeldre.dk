<?php

/**
 * @file
 * Theme implementation SOF pdf generator. This html will be converted to pdf file
 */
 
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php //print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php //print $language->dir; ?>">
  <head>
    <?php print $css; ?>
  </head>
  <body>
      
    <!--COVER PAGE-->
        <div class="sof-pdf-cover" ><?php print render($title); ?></div>
    <!--COVER PAGE-->
    
    <!--CONTENT-->
    <div class="sof-pdf-content"><?php print render($content); ?></div>
    <!--CONTENT-->
   
  </body>
</html>
