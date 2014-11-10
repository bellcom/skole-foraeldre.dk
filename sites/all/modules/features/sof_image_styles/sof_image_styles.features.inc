<?php
/**
 * @file
 * sof_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function sof_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: article_top_slider.
  $styles['article_top_slider'] = array(
    'name' => 'article_top_slider',
    'label' => 'Article top slider (750x500)',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: publication_related.
  $styles['publication_related'] = array(
    'name' => 'publication_related',
    'label' => 'Publication related image',
    'effects' => array(
      1 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 430,
          'height' => 570,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: related_content_reference_image.
  $styles['related_content_reference_image'] = array(
    'name' => 'related_content_reference_image',
    'label' => 'Related content reference image (690x460)',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 690,
          'height' => 460,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
