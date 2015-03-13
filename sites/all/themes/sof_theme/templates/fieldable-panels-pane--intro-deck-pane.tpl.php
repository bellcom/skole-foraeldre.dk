<?php
/**
 * @file
 * Default template implementation to display the value,
 * of a fieldable panel pane.
 * fieldable-panels-pane.tpl.php
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_suffix); ?>
  <div class="intro-deck-group-first">
    <?php print render($content['field_teaser']); ?>
    <?php print render($content['field_single_link']); ?>
  </div>
  <div class="intro-deck-group">
    <?php print render($content['group_first_link_group']); ?>
  </div>
  <div class="intro-deck-group">
    <?php print render($content['group_second_links_group']); ?>
  </div>
</div>
