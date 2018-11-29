<?php

/**
 * @file
 * linkit_plugin_pdf_download.class.php
 *
 * Define Linkit node plugin class update.
 * Ment for links to pdf files of the publication.
 *
 * @author Goce Shutinoski <gsutinoski@propeople.dk>
 * @author Lachezar Valchev <lachezar@propeople.dk>
 */

/**
 * Reprecents a Linkit node search plugin.
 */
class LinkitPluginPdfDownload extends LinkitSearchPluginNode {

  /**
   * Overrides LinkitSearchPluginEntity::createLabel().
   */
  public function createLabel($entity) {
    return t('Download sample of:') . ' ' . entity_label($this->plugin['entity_type'], $entity);
  }

  /**
   * Overrides LinkitSearchPluginEntity::createPath().
   */
  public function createPath($entity) {
    $options = array();

    // Create the URI for the entity.
    $uri = 'sof-pdf-generate/' . $entity->nid;

    // Handle multilingual sites.
    if (isset($entity->language) && $entity->language != LANGUAGE_NONE && drupal_multilingual() && language_negotiation_get_any(LOCALE_LANGUAGE_NEGOTIATION_URL)) {
      $languages = language_list('enabled');

      // Only use enabled languages.
      $languages = $languages[1];

      if ($languages && isset($languages[$entity->language])) {
        $options['language'] = $languages[$entity->language];
      }
    }

    // Process the uri with the insert pluing.
    $path = linkit_get_insert_plugin_processed_path($this->profile, $uri, $options);

    return $path;
  }

  /**
   * Overrides LinkitSearchPluginEntity::createGroup().
   */
  public function createGroup($entity) {
    $group = t('SOF publication pdf');

    return $group;
  }

  /**
   * Overrides LinkitSearchPluginEntity::getQueryInstance().
   */
  public function getQueryInstance() {
    // Call the parent getQueryInstance method.
    parent::getQueryInstance();

    // Specify publications only.
    $this->query->propertyCondition($this->entity_key_bundle, 'publication', '=');
  }

  /**
   * Overrides LinkitSearchPluginNode::buildSettingsForm().
   */
  public function buildSettingsForm() {
    // Get the parent settings form.
    $form = parent::buildSettingsForm();

    // Unset extra options for bundles.
    // We are working with publications only.
    unset($form['sof_pdf_generator']['bundles']);
    unset($form['sof_pdf_generator']['group_by_bundle']);

    return $form;
  }

}
