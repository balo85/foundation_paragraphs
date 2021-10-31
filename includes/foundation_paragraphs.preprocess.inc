<?php

use Drupal\Component\Utility\NestedArray;
use Drupal\file\Entity\File;
use Drupal\image\Entity\ImageStyle;
use Drupal\views\Views;
use Drupal\Core\Url;

function foundation_paragraphs_preprocess_paragraph(&$variables) {
  $paragraph    = $variables['paragraph'];
  $parBundle    = $paragraph->bundle();

  _bp_preprocessParagraph_commonInfos($variables, $paragraph);
  _bp_preprocessParagraph_topBottomSpaces($variables, $paragraph);

  switch($parBundle) {
    case 'foundation_grid':
      _bp_preprocessParagraph_gridEnhancer($variables, $paragraph);
      break;

    case 'foundation_cell':
      _bp_preprocessParagraph_cellEnhancer($variables, $paragraph);
      break;
  }
}

/**
 * Variabili comuni
 * Elabora eventuali id e classi custom aggiuntive impostate manualmente
 *
 * @param $variables
 * @param $paragraph
 */
function _bp_preprocessParagraph_commonInfos(&$variables, $paragraph) {
  // Gestisco eventuali id custom ad hoc
  if($paragraph->hasField('field_foundation_id')) {
    $strId = (!$paragraph->field_foundation_id->isEmpty()) ? trim((string)$paragraph->field_foundation_id->getString()) : '';
    if($strId !== '') { $variables['attributes']['id'] = $strId; }
  }

  // Gestisco eventuali classi custom ad hoc
  if($paragraph->hasField('field_foundation_classes')) {
    $strCls   = (!$paragraph->field_foundation_classes->isEmpty()) ? trim((string)$paragraph->field_foundation_classes->getString()) : '';
    $classes  = ($strCls !== '') ? explode(" ", $strCls) : null;
    if($classes && count($classes) > 0) {
      foreach($classes as $class) { $variables['attributes']['class'][] = $class; }
    }
  }
}

/**
 * Variabili comuni
 * Elabora eventuali classi per spaziature come padding e margin superiori ed inferiori
 *
 * @param $variables
 * @param $paragraph
 */
function _bp_preprocessParagraph_topBottomSpaces(&$variables, $paragraph) {
  if($paragraph->hasField('field_foundation_top_margin')) {
    $strSpace = (!$paragraph->field_foundation_top_margin->isEmpty()) ? trim((string)$paragraph->field_foundation_top_margin->getString()) : '';
    if($strSpace !== '' && $strSpace !== 'none') { $variables['attributes']['class'][] = 'marginTop-'.$strSpace; }
  }

  if($paragraph->hasField('field_foundation_bottom_margin')) {
    $strSpace = (!$paragraph->field_foundation_bottom_margin->isEmpty()) ? trim((string)$paragraph->field_foundation_bottom_margin->getString()) : '';
    if($strSpace !== '' && $strSpace !== 'none') { $variables['attributes']['class'][] = 'marginBot-'.$strSpace; }
  }

  if($paragraph->hasField('field_foundation_top_padding')) {
    $strSpace = (!$paragraph->field_foundation_top_padding->isEmpty()) ? trim((string)$paragraph->field_foundation_top_padding->getString()) : '';
    if($strSpace !== '' && $strSpace !== 'none') { $variables['attributes']['class'][] = 'paddingTop-'.$strSpace; }
  }

  if($paragraph->hasField('field_foundation_bottom_padding')) {
    $strSpace = (!$paragraph->field_foundation_bottom_padding->isEmpty()) ? trim((string)$paragraph->field_foundation_bottom_padding->getString()) : '';
    if($strSpace !== '' && $strSpace !== 'none') { $variables['attributes']['class'][] = 'paddingBot-'.$strSpace; }
  }
}

/**
 * Variabili di grid
 * Elabora le variabili per definire il tipo di contanier ed il gutter
 *
 * Container: none / standard / fluid / full
 * Gutter: none / margin / padding / both
 * Vertical alignment: none / top / middle / bottom / stretch
 * Horizontal alignment: none / right / center / justify / spaced
 * Collapse gutters
 *
 * @param $variables
 * @param $paragraph
 */
function _bp_preprocessParagraph_gridEnhancer(&$variables, $paragraph) {
  $strContainer = (!$paragraph->field_foundation_grid_container->isEmpty()) ? trim((string)$paragraph->field_foundation_grid_container->getString()) : 'standard';
  $variables['containerType'] = $strContainer;

  $strVertAlign = (!$paragraph->field_foundation_vert_align->isEmpty()) ? trim((string)$paragraph->field_foundation_vert_align->getString()) : 'none';
  $variables['vertAlign'] = ($strVertAlign !== 'none') ? 'align-'.$strVertAlign : '';

  $strHorizAlign = (!$paragraph->field_foundation_horiz_align->isEmpty()) ? trim((string)$paragraph->field_foundation_horiz_align->getString()) : 'none';
  $variables['horizAlign'] = ($strHorizAlign !== 'none') ? 'align-'.$strHorizAlign : '';

  // Gestione gutter
  $strGutter      = (!$paragraph->field_foundation_grid_gutters->isEmpty()) ? trim((string)$paragraph->field_foundation_grid_gutters->getString()) : 'margin';
  $strGutCollapse = (!$paragraph->field_foundation_collapse_gutters->isEmpty()) ? trim((string)$paragraph->field_foundation_collapse_gutters->getString()) : 'none';
  switch($strGutter) {
    case 'margin':
      $variables['gutterType']      = 'grid-margin-x';
      $variables['gutterCollapse']  = ($strGutCollapse !== 'none') ? $strGutCollapse.'-margin-collapse' : '';
      break;
    case 'padding':
      $variables['gutterType']      = 'grid-padding-x';
      $variables['gutterCollapse']  = ($strGutCollapse !== 'none') ? $strGutCollapse.'-padding-collapse' : '';
      break;
    case 'both':
      $variables['gutterType']      = 'grid-margin-x grid-padding-x';
      $variables['gutterCollapse']  = ($strGutCollapse !== 'none') ? $strGutCollapse.'-margin-collapse '.$strGutCollapse.'-padding-collapse' : '';
      break;
    case 'none':
    default:
    $variables['gutterType']      = '';
    $variables['gutterCollapse']  = '';
      break;
  }
}

/**
 * Variabili di cell
 * Elabora le classi per definire allineamento, spazio ed offset della singola cella
 *
 * @param $variables
 * @param $paragraph
 */
function _bp_preprocessParagraph_cellEnhancer(&$variables, $paragraph) {
  $classes  = [];

  $strSizeS   = (!$paragraph->field_foundation_size_small->isEmpty()) ? trim((string)$paragraph->field_foundation_size_small->getString()) : '12';
  $strOffS    = (!$paragraph->field_foundation_offset_small->isEmpty()) ? trim((string)$paragraph->field_foundation_offset_small->getString()) : 'none';
  $classes[]  = _bp_preprocessParagraph_cellEnhancer_getSize($strSizeS, 'small');
  $classes[]  = _bp_preprocessParagraph_cellEnhancer_getOffset($strOffS, 'small');

  $strSizeM   = (!$paragraph->field_foundation_size_medium->isEmpty()) ? trim((string)$paragraph->field_foundation_size_medium->getString()) : 'none';
  $strOffM    = (!$paragraph->field_foundation_offset_medium->isEmpty()) ? trim((string)$paragraph->field_foundation_offset_medium->getString()) : 'none';
  $classes[]  = _bp_preprocessParagraph_cellEnhancer_getSize($strSizeM, 'medium');
  $classes[]  = _bp_preprocessParagraph_cellEnhancer_getOffset($strOffM, 'medium');

  $strSizeL   = (!$paragraph->field_foundation_size_large->isEmpty()) ? trim((string)$paragraph->field_foundation_size_large->getString()) : 'none';
  $strOffL    = (!$paragraph->field_foundation_offset_large->isEmpty()) ? trim((string)$paragraph->field_foundation_offset_large->getString()) : 'none';
  $classes[]  = _bp_preprocessParagraph_cellEnhancer_getSize($strSizeL, 'large');
  $classes[]  = _bp_preprocessParagraph_cellEnhancer_getOffset($strOffL, 'large');

  $strVertAlign = (!$paragraph->field_foundation_vert_align_self->isEmpty()) ? trim((string)$paragraph->field_foundation_vert_align_self->getString()) : 'none';
  $classes[]    = ($strVertAlign !== 'none') ? 'align-self-'.$strVertAlign : '';

  // Aggiungo tutte le classi elaborate
  $classes = array_filter($classes, fn($value) => !is_null($value) && $value !== '');
  if(count($classes) > 0) {
    foreach ($classes as $class) {
      $variables['attributes']['class'][] = $class;
    }
  }
}
function _bp_preprocessParagraph_cellEnhancer_getSize($value, $mq){
  return ($value !== 'none') ? $mq.'-'.$value : '';
}
function _bp_preprocessParagraph_cellEnhancer_getOffset($value, $mq){
  return ($value !== 'none') ? $mq.'-offset-'.$value : '';
}
