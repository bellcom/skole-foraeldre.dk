<?php

/**
 * @file
 * Theme implementation for image on the top of the pdf file.
 * 
 * Variables:
 *  -$image : Image renderable array
 */
 
?>
<div class="sof-pdf-top-image">
   <?php print render($image); ?>
   <p> <?php print $image[0]['#item']['title']; ?></p>
</div>