<?php

/**
 * @file
 * sof_pdf_generator_pages.tpl.php
 *
 * Theme implementation for rest of the content of the pdf file.
 *
 * Variables:
 *  -$content : Array with print fields (image, title, teaser and body)
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */
?>

<div class="sof-pdf-page-template">
  <div class='content'></div>
</div>
<div class="sof-pdf-all-content"></div>
<div class="sof-pdf-content" >
  <article id="sof-pdf-contents">
    <header>
      <?php print render($content['image']); ?>
      <h1><?php print render($content['title']); ?></h1>
      <p><?php print render($content['teaser']); ?></p>
    </header>
    <?php print render($content['body']); ?>
  </article>
</div>
