<?php if($panetitle != ""):?>
	<h2 class="fixed-pane-title"><?php print render($panetitle);?></h2>
<?php endif; ?>
<?php if($variables['elements']['#fieldable_panels_pane']->bundle == 'magazine_pane'):?>
	<h3 class="fixed-pane-title-magazine"><?php print render($title);?></h2>
<?php endif; ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_suffix); ?>
  <?php print $fields; ?>
</div>
