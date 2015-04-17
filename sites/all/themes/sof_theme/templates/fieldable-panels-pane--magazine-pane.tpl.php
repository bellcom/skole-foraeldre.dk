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
    <?php if(!empty($panetitle)):?>
      <h2 class="fixed-pane-title"><?php print render($panetitle);?></h2>
    <?php endif; ?>
    <h3 class="fixed-pane-title-magazine"><?php print render($subtitle);?></h2>
    <div class="<?php print $classes; ?>" <?php print $attributes; ?>>
      <?php print render($title_suffix); ?>
      <?php hide($content['field_magazine_category'])?>
      <?php hide($content['field_magazine_links'])?>
      <?php print render($content); ?>
      <div class="mag-deck-right-group">
          <?php print render($content['field_magazine_category']);?>
          <?php print render($content['field_magazine_links']);?>
      </div>
    </div>
  </div>
</div>
