<?php

/**
 * Implements hook_theme().
 */
function foundation_paragraphs_theme($existing, $type, $theme, $path) {
  return [
    'foundation_grid'   => ['base hook' => 'paragraph'],
    'foundation_cell'   => ['base hook' => 'paragraph'],
    'foundation_text'   => ['base hook' => 'paragraph'],
    'foundation_image'  => ['base hook' => 'paragraph'],
  ];
}

/**
 * Implements hook_theme_registry_alter().
 *
 * Check for the .html.twig files in the folders of
 * - current module (foundation_paragraphs/templates)
 * - current theme (xxx/templates/paragraphs)
 *
 * @param type $theme_registry
 */
function foundation_paragraphs_theme_registry_alter(&$theme_registry){
  $fsService  = \Drupal::service('file_system');
  $extension  = '.html.twig';

  $actTheme     =  \Drupal::config('system.theme')->get('default');
  $modulePath   = drupal_get_path('module', 'foundation_paragraphs');
  $themePath    = drupal_get_path('theme', $actTheme);

  $dir = $modulePath . '/templates';
  if(is_dir($dir)) {
    $moduleFiles  = $fsService->scanDirectory($dir, '/' . preg_quote($extension) . '$/');
    _foundation_paragraphs_theme_registry_alter_partial($theme_registry, $moduleFiles, $extension, $modulePath, 'module', $fsService);
  }

  $dir = $themePath . '/templates/paragraphs';
  if(is_dir($dir)) {
    $themeFiles   = $fsService->scanDirectory($dir, '/' . preg_quote($extension) . '$/');
    _foundation_paragraphs_theme_registry_alter_partial($theme_registry, $themeFiles, $extension, $themePath, 'theme_engine', $fsService);
  }
}

/**
 * Iterare the single .html.twig file recived and che if exist.
 * If possibile, it add them to the theme registry to use them.
 *
 * @param $theme_registry
 * @param $files
 * @param $extension
 * @param $myPath
 * @param $type
 */
function _foundation_paragraphs_theme_registry_alter_partial(&$theme_registry, $files, $extension, $myPath, $type, $fsService) {
  foreach ($files as $file){
    $template = $fsService->basename($file->filename, $extension);
    $theme    = str_replace('-', '_', $template);
    $exp      = explode('__', $theme, 2);

    if(count($exp) === 2){
      $base_theme = $exp[0];
      $specific   = $exp[1];

      // Don't override base theme.
      if(!empty($specific) && isset($theme_registry[$base_theme])){
        $theme_info = array(
          'render element'        => (isset($theme_registry[$base_theme]['render element'])) ? $theme_registry[$base_theme]['render element'] : '',
          'type'                  => $type,
          'theme path'            => $myPath,
          'template'              => $template,
          'path'                  => \Drupal::service('file_system')->dirname($file->uri),
          'preprocess functions'  => (isset($theme_registry[$base_theme]['preprocess functions'])) ? $theme_registry[$base_theme]['preprocess functions'] : array(),
          'base hook'             => $base_theme,
          'variables'             => (isset($theme_registry[$base_theme]['variables'])) ? $theme_registry[$base_theme]['variables'] : null,
        );

        $theme_registry[$theme] = $theme_info;
      }
    }
  }
}

