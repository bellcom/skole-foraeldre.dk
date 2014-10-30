<?php if($variables['panetitle'] != ""):?>
	<h2 class="fixed-pane-title"><?php print render($variables['panetitle']);?></h2>
<?php endif; ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_suffix); ?>
  <?php print $fields; ?>
</div>
