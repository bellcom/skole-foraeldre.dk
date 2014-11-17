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
   <?php if($image[0]['#item']['title']):?>
   	<p> <?php print $image[0]['#item']['title']; ?></p>
   <?php endif; ?>
</div>