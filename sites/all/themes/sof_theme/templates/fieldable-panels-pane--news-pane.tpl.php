<h2 class="fixed-pane-title"><?php print render($variables['panetitle']);?></h2>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_suffix); ?>
  <!-- Top Content -->
  <div class="news-deck-top-content">
  	   <?php print render($content['field_primary_referenced_node']);?>
  </div>
     <!-- Bottom News Deck -->
  <div class="news-deck-bottom-content">
  	<!-- Left Content -->
  	<div class="news-deck-bottom-left-content">
  		<?php print render($content['field_single_link']);?>
  	</div>
  	<!-- Right Content -->
  	<div class="news-deck-bottom-right-content">
	<!-- Related terms block -->
	<?php if ( $followlinks = block_load('follow', 'site')): ?>
		<h3 class="follow-title"><?php print t('Follow Us');?></h3>
		<div class="follow-links">
		  <a href="" class="news-deck-newsletter">Newsletter</a>
		   <?php 
		    $block = module_invoke('follow', 'block_view', 'site');
			 print render($block); 
		   ?>
		</div>
	<?php endif; ?>
  	</div>
  </div>

</div>