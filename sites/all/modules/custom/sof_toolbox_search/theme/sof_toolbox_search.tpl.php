<?php

/**
 * @file
 * Default theme implementation for the pane.
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 */

?>
<div class="sof_toolbox_wrapper" >
    <?php foreach ($items as $item) : ?>
    <?php print render($item); ?>
    <?php endforeach; ?>
</div>
