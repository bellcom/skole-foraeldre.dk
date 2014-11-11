<?php

/**
 * @file
 * Theme implementation for footer social media links.
 * 
 * Variables:
 *  - $items : Array of content per link
 * 
 */
 
?>

<div class="sof_footer_social_media_block">
	<?php foreach ($items as $key=>$item) : ?>
		 <div class="footer_social_media_<?php print $key; ?>" >
		   <div class="sof_footer_social_media_icon" >
<<<<<<< HEAD
		       <img src="<?php print $item['icon']; ?>" />
=======
		       <img src="<?php print $item['icon']; ?>" height="50px" />
>>>>>>> 9023d10fe4eede69f33f626df14ffebfd242df0c
		   </div>
		   <h5><?php print $item['title']?></h5>  
		   <p><?php print $item['description']?></p>
		    <?php print $item['read_more']?>
		 </div>
	<?php endforeach; ?>
</div>