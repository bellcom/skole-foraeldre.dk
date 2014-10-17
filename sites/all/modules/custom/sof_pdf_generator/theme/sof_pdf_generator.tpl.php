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
    <?php print $js; ?>
    <script type="text/javascript">
        jQuery(function(){
            jQuery('.split-this').columnize({ columns: 2 });
        });
    </script>
  </head>
  <body>
      
    <!--COVER PAGE-->
        <div class="sof-pdf-cover" ><?php print render($title); ?></div>
    <!--COVER PAGE-->
    
    <!--CONTENT-->
    <div class="sof-pdf-content">
        <?php foreach ($content as $node) : ?>
            <article>
                <header>
                  <h1><?php print render($node['title']); ?></h1>
                  <p><?php print render($node['teaser']); ?></p>
                </header>
                <div class="split-this">
                    <?php print render($node['body']); ?>
                </div>
            </article>
        <?php endforeach; ?>
    </div>
    <!--CONTENT-->
   
  </body>
</html>
