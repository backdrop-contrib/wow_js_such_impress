<?php

/**
 * @file
 * Contains the administration pages for WowJS.
 *
 */
function wow_js_such_impress_settings($form_state) {

  $form['wow_js_such_impress_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Show animations on specific pages'),
    '#options' => array(0 => t('All pages except those listed'), 1 => t('Only the listed pages')),
    '#default_value' => config_get('wow_js_such_impress.settings', 'wow_js_such_impress_visibility'),
  );
  $form['wow_js_such_impress_pages'] = array(
    '#type' => 'textarea',
    '#title' => '<span class="element-invisible">' . t('Pages') . '</span>',
    '#default_value' => config_get('wow_js_such_impress.settings', 'wow_js_such_impress_pages'),
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  $form['wow_js_such_impress_demo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable demo animations'),
    '#default_value' => config_get('wow_js_such_impress.settings', 'wow_js_such_impress_demo'),
    '#description' => t('This enables demo animations to show how this module can work.  You can write your own custom Javascript and CSS based on http://mynameismatthieu.com/WOW/docs.html'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * Submit handler for module_settings_form().
 */
function wow_js_such_impress_settings_submit($form, &$form_state) {
    $config = config('wow_js_such_impress.settings');
    foreach ($form_state['values'] as $key => $value)
    {
      $config->set($key, $value);
    }

    $config->save();
    backdrop_set_message(t('The configuration options have been saved.'));
}
?>
