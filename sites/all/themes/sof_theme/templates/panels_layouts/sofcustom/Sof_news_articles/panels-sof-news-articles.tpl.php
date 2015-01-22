<?php
/**
 * @file
 * Template for News and Articles.
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
<div class="article-news-main-container">
  <div class="top-article-content">
    <div class="left-article-region">
      <?php print $content['left']; ?>
    </div>
    <div class="right-article-region">
      <?php print $content['right']; ?>
    </div>
  </div>
  <div class="bottom-article-region">
    <?php print $content['bottom']; ?>
  </div>
</div>
