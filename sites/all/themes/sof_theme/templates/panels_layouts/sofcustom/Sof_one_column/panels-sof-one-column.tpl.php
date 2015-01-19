<?php
/**
 * @file
 * Template for a 1 column panel layout.
 *
 * This template provides a three column panel display layout, with
 * each column roughly equal in width and one at the bottom with 100%.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom column.
 */
?>
<div class="panel-display panel-3col-custom clearfix" <?php if (!empty($css_id)) : print "id=\"$css_id\""; endif; ?>>
  <div class="panel-panel panel-col-top">
    <div class="panel-panel panel-col-full-main">
	<?php print $content['main']; ?>
    </div>
  </div>
</div>
