<?php

/**
 * Implements hook_language_fallback_candidates_OPERATION_alter().

 * Needed to fix https://www.drupal.org/project/paragraphs/issues/2827974
 */
function foundation_paragraphs_language_fallback_candidates_entity_view_alter(array &$candidates, array $context) {
  $data = $context['data'];

  if($data instanceof \Drupal\paragraphs\Entity\Paragraph) {
    $langcode = Drupal::languageManager()->getCurrentLanguage()->getId();
    $candidates = [$langcode];
  }
}
