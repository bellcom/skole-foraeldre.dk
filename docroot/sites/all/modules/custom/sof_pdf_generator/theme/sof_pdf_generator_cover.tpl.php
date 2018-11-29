<?php

/**
 * @file
 * sof_pdf_generator_cover.tpl.php
 *
 * Theme implementation for cover page of the pdf file.
 *
 * Variables:
 *  - $title : Title of the cover page
 *  - $teaser: Small text under the title
 *  - $color : Background color of the page
 *  - $logo  : Logo of the page
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */
?>

<div class="sof-pdf-cover" style="background: <?php print $color; ?>" >
  <div class="sof-pdf-cover-vertical">
    <h1><?php print $title; ?></h1>
    <p><?php print $teaser; ?></p>
  </div>
  <img src="<?php print $logo; ?>" alt="logo" title="logo" class="sof-pdf-logo" />
</div>
