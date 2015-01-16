<?php
/**
 * @file
 * Default template implementation to display the value,
 * of a magazine pane.
 * fieldable-panels-pane--magazine-pane.tpl.php
 */
?>
<div class="magazine-deck-background-wrapper" style="background-image: url(<?php print $magazine_background; ?>);" >
  <div class="magazine-deck-inner-block">
    <?php if($panetitle != ""):?>
      <h2 class="fixed-pane-title"><?php print render($panetitle);?></h2>
    <?php endif; ?>
    <h3 class="fixed-pane-title-magazine"><?php print render($title);?></h2>
    <div class="<?php print $classes; ?>" <?php print $attributes; ?>>
      <?php print render($title_suffix); ?>
      <?php print render($content); ?>
    </div>
  </div>
</div>
