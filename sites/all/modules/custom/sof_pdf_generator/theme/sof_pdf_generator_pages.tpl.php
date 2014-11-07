<?php

/**
 * @file
 * Theme implementation for rest of the content of the pdf file.
 * 
 * Variables:
 *  -$content : Array with print fields (title, teaser and body)
 */

?>
<div class="sof-pdf-content">
    <?php foreach ($content as $node) : ?>
        <article>
            <header>
              <h1><?php print render($node['title']); ?></h1>
              <p><?php print render($node['teaser']); ?></p>
            </header>
            <div class="sof-column-content">
                <?php print render($node['body']); ?>
            </div>
        </article>
    <?php endforeach; ?>
</div>