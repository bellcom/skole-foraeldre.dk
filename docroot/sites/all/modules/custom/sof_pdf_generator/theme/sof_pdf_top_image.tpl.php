<?php

/**
 * @file
 * sof_pdf_top_image.tpl.php
 *
 * Theme implementation for image on the top of the pdf file.
 *
 * Variables:
 *  -$image : Image renderable array
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */
?>

<div class="sof-pdf-top-image">
  <?php print render($image); ?>
  <?php if($image[0]['#item']['title']):?>
    <p> <?php print $image[0]['#item']['title']; ?></p>
  <?php endif; ?>
</div>
