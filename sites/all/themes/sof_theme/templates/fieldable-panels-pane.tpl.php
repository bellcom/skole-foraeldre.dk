<?php
/**
 * @file
 * Default template implementation to display the value,
 * of a fieldable panel pane.
 * fieldable-panels-pane.tpl.php
 */
?>
<?php if(!empty($panetitle)):?>
  <h2 class="fixed-pane-title"><?php print render($panetitle);?></h2>
<?php endif; ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_suffix); ?>
  <?php print $fields; ?>
</div>
