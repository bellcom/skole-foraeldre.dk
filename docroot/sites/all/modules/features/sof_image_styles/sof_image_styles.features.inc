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
    'label' => 'Article top slider (750x500)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: magazine_deck_background.
  $styles['magazine_deck_background'] = array(
    'label' => 'Magazine deck background',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1920,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: publication_default_image_393x522_.
  $styles['publication_default_image_393x522_'] = array(
    'label' => 'Publication default image(393x522)',
    'effects' => array(
      3 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 393,
          'height' => 522,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: publication_related.
  $styles['publication_related'] = array(
    'label' => 'Publication related image(380x520)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 380,
          'height' => 520,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 380,
          'height' => 520,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: related_content_reference_image.
  $styles['related_content_reference_image'] = array(
    'label' => 'Related content reference image (690x460)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 690,
          'height' => 460,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: teaser_image.
  $styles['teaser_image'] = array(
    'label' => 'Teaser image (360x240)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 380,
          'height' => 260,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
