<?php

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_alter().
 * Add custom css style for node edit
 *
 * @param $form
 * @param FormStateInterface $form_state
 * @param $form_id
 */
function foundation_paragraphs_form_alter(&$form, FormStateInterface $form_state, $form_id) {
  $matchAdd = '/^node_(.+)_form$/';
  $matchEdit = '/^node_(.+)_edit_form$/';
  if(preg_match($matchAdd, $form_id) || preg_match($matchEdit, $form_id)) {
    $form['#attached']['library'][] = 'foundation_paragraphs/admin_styles';
  }
}
