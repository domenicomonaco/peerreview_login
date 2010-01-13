<?php
// $Id$

/**
 * Author Domenico Monaco
 * kiuz.4ever@gmail.com
 * http://www.kiuz.it
 * License: GPLv2
 **/

function peerreview_login_setting() {

  $form['peerreview_login_badge_mode'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Attivazione PeerReview login Module',
    '#options' => array('enable'=>t('Enable')),
    '#default_value' => variable_get('peerreview_login_badge_mode', ''),
    '#description' => 'Opzione principale dell\'intero modulo, se attivo da accesso a tutte le altre impostazione, se inattivo impedirà il completo funzionamento del modulo.',
  );
  
  $form['peerreview_login_badge_submode'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Attivazione della barra per gli <em>stati</em> disponibili',
    '#options' => array(
      'unlogged'=> t('Unlogged User'),
      'logged'=> t('Logged User')
      ),
    '#default_value' => variable_get('peerreview_login_badge_submode', ''),
    '#disabled'=>_prl_check_var('peerreview_login_badge_mode','enable'),
    '#description' => 'Permette di attivare/disattivare genericamente in modo separato la visualizzazione della barra in base allo stato in cui si trova l\'utente che accede al sito.',
  );
  
  $form['peerreview_login_bar_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => variable_get('peerreview_login_bar_height', ''),
    '#size' => 5,
    '#maxlength' => 4,
    '#disabled'=>_prl_check_var('peerreview_login_badge_mode','enable'),
    '#description' => t('Inserisci l\'altezza massima che devono possedere le icone nel badge. Vincolerà solo la dimensione delle icone in altezza non in larghezza. Inserire la dimensione in pixel comprensivo della dicitura "px", es. "48px"')
  );
  
  $form['peerreview_login_logged_buttons'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Attiva gli elementi della barra per lo stato <em>LOGGED</em>',
    '#options' => _prl_check_element_list('logged'),
    '#default_value' => variable_get('peerreview_login_logged_buttons', ''),
    '#disabled'=>_prl_check_var('peerreview_login_badge_submode','logged'),
    '#description' => 'Selezioni gli elementi che desideri attivare nella barra nello stato LOGGED. La presenza o meno di un elemento nella lista è dovuto dalla sua stessa definizione.',
  );

  $form['peerreview_login_unlogged_buttons'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Attiva gli elementi della barra per lo stato <em>UNLOGGED</em>',
    '#options' => _prl_check_element_list('unlogged'),
    '#default_value' => variable_get('peerreview_login_unlogged_buttons', ''),
    '#disabled'=>_prl_check_var('peerreview_login_badge_submode','unlogged'),
    '#description' => 'Selezioni gli elementi che desideri attivare nella barra nello stato UNLOGGED. La presenza o meno di un elemento nella lista è dovuto dalla sua stessa definizione.',
  );
  

  /**
    * Wizard Slider Block Options
    **/

  $form['wizard_slider'] = array(
   '#type' => 'fieldset',
    '#title' => t('Wizard Slider Block Options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['wizard_slider']['wizard_slider_logged'] = array(
    '#type' => 'fieldset',
    '#title' => t('Wizard Slider Block Options on LOGGED state '),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE
  );

  $form['wizard_slider']['wizard_slider_logged']['wizard_slider_logged_element'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Attiva elementi nello Wizard Slider Block nello stato LOGGED',
    '#options' => _prl_check_element_list('logged'),
    '#default_value' => variable_get('wizard_slider_logged_element', ''),
    '#description' => ''
  );

  foreach(variable_get('wizard_slider_logged_element', '') as $wizard_logged_element){
    if(!($wizard_logged_element == '0')){
      
      $form['wizard_slider']['wizard_slider_logged']['wizard_slider_logged_element_' . $wizard_logged_element] = array(
        '#type' => 'fieldset',
        '#title' => t('Opzioni per ' . $wizard_logged_element),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE
      );

      $form['wizard_slider']['wizard_slider_logged']['wizard_slider_logged_element_' . $wizard_logged_element]['wizard_slider_logged_element_' . $wizard_logged_element . '_text'] = array(
        '#type' => 'select',
        '#title' => t('Text option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('wizard_slider_logged_element_' . $wizard_logged_element . '_text', 0),
        '#disabled'=>_prl_check_var('peerreview_login_logged_buttons','wizard'),
      );
  
      $form['wizard_slider']['wizard_slider_logged']['wizard_slider_logged_element_' . $wizard_logged_element]['wizard_slider_logged_element_' . $wizard_logged_element . '_icon'] = array(
        '#type' => 'select',
        '#title' => t('Icon option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('wizard_slider_logged_element_' . $wizard_logged_element . '_icon', 0),
        '#disabled'=>_prl_check_var('peerreview_login_logged_buttons','wizard'),
      );
      
      $form['wizard_slider']['wizard_slider_logged']['wizard_slider_logged_element_' . $wizard_logged_element]['wizard_slider_logged_element_' . $wizard_logged_element . '_link'] = array(
        '#type' => 'select',
        '#title' => t('Link option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('wizard_slider_logged_element_' . $wizard_logged_element . '_link', 0),
        '#disabled'=>_prl_check_var('peerreview_login_logged_buttons','wizard'),
      );
  
    }
  }

  $form['wizard_slider']['wizard_slider_unlogged'] = array(
    '#type' => 'fieldset',
    '#title' => t('Wizard Slider Block Options on UNLOGGED state '),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE
  );

  $form['wizard_slider']['wizard_slider_unlogged']['wizard_slider_unlogged_element'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Attiva elementi nello Wizard Slider Block nello stato UNLOGGED',
    '#options' => _prl_check_element_list('unlogged'),
    '#default_value' => variable_get('wizard_slider_unlogged_element', ''),
    '#description' => '',
  );

  foreach(variable_get('wizard_slider_unlogged_element', '') as $wizard_unlogged_element){
    if(!($wizard_unlogged_element == '0')){
      
      $form['wizard_slider']['wizard_slider_unlogged']['wizard_slider_unlogged_element_' . $wizard_unlogged_element] = array(
       '#type' => 'fieldset',
       '#title' => t('Opzioni per ' . $wizard_unlogged_element),
       '#collapsible' => TRUE,
       '#collapsed' => TRUE
     );

     $form['wizard_slider']['wizard_slider_unlogged']['wizard_slider_unlogged_element_' . $wizard_unlogged_element]['wizard_slider_unlogged_element_' . $wizard_unlogged_element . '_text'] = array(
       '#type' => 'select',
       '#title' => t('Text option'),
       '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
       '#description' => t(''),
       '#default_value' => variable_get('wizard_slider_unlogged_element_' . $wizard_unlogged_element . '_text', 0),
       '#disabled'=>_prl_check_var('peerreview_login_unlogged_buttons','wizard'),
     );
     
      $form['wizard_slider']['wizard_slider_unlogged']['wizard_slider_unlogged_element_' . $wizard_unlogged_element]['wizard_slider_unlogged_element_' . $wizard_unlogged_element . '_icon'] = array(
        '#type' => 'select',
        '#title' => t('Icon option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('wizard_slider_unlogged_element_' . $wizard_unlogged_element . '_icon', 0),
        '#disabled'=>_prl_check_var('peerreview_login_unlogged_buttons','wizard'),
      );

      $form['wizard_slider']['wizard_slider_unlogged']['wizard_slider_unlogged_element_' . $wizard_unlogged_element]['wizard_slider_unlogged_element_' . $wizard_unlogged_element . '_link'] = array(
        '#type' => 'select',
        '#title' => t('Link option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('wizard_slider_unlogged_element_' . $wizard_unlogged_element . '_link', 0),
        '#disabled'=>_prl_check_var('peerreview_login_unlogged_buttons','wizard'),
      );

    }
  }
  
  /**
    * 
    **/
  $form['fixed_bar'] = array(
   '#type' => 'fieldset',
    '#title' => t('Fixed Bar Options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fixed_bar']['fixed_bar_logged'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fixed Bar Options nello stato LOGGED'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE
  );

  //peerreview_login_logged_buttons
  foreach(variable_get('peerreview_login_logged_buttons', '') as $bar_logged_element){
    if(!($bar_logged_element == '0')){
      
      $form['fixed_bar']['fixed_bar_logged']['fixed_bar_logged_element_' . $bar_logged_element] = array(
        '#type' => 'fieldset',
        '#title' => t('Opzioni per ' . $bar_logged_element),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE
      );

      $form['fixed_bar']['fixed_bar_logged']['fixed_bar_logged_element_' . $bar_logged_element]['peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_text'] = array(
        '#type' => 'select',
        '#title' => t('Text option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_text', 0),
        '#disabled'=>_prl_check_var('peerreview_login_badge_submode','logged'),
      );
  
      $form['fixed_bar']['fixed_bar_logged']['fixed_bar_logged_element_' . $bar_logged_element]['peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_icon'] = array(
        '#type' => 'select',
        '#title' => t('Icon option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_icon', 0),
        '#disabled'=>_prl_check_var('peerreview_login_badge_submode','logged'),
      );
      
      $form['fixed_bar']['fixed_bar_logged']['fixed_bar_logged_element_' . $bar_logged_element]['peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_link'] = array(
        '#type' => 'select',
        '#title' => t('Link option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_link', 0),
        '#disabled'=>_prl_check_var('peerreview_login_badge_submode','logged'),
      );
  
    }
  }
   
  $form['fixed_bar']['fixed_bar_unlogged'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fixed Bar Options nello stato UNLOGGED'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE
  );
  
  //peerreview_login_unlogged_buttons
  foreach(variable_get('peerreview_login_unlogged_buttons', '') as $bar_unlogged_element){
    if(!($bar_unlogged_element == '0')){
      
      $form['fixed_bar']['fixed_bar_unlogged']['fixed_bar_unlogged_element_' . $bar_unlogged_element] = array(
        '#type' => 'fieldset',
        '#title' => t('Opzioni per ' . $bar_unlogged_element),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE
      );

      $form['fixed_bar']['fixed_bar_unlogged']['fixed_bar_unlogged_element_' . $bar_unlogged_element]['peerreview_login_fixed_bar_unlogged_element_' . $bar_unlogged_element . '_text'] = array(
        '#type' => 'select',
        '#title' => t('Text option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_text', 0),
        '#disabled'=>_prl_check_var('peerreview_login_badge_submode','unlogged'),
      );
  
      $form['fixed_bar']['fixed_bar_unlogged']['fixed_bar_unlogged_element_' . $bar_unlogged_element]['peerreview_login_fixed_bar_unlogged_element_' . $bar_unlogged_element . '_icon'] = array(
        '#type' => 'select',
        '#title' => t('Icon option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_icon', 0),
        '#disabled'=>_prl_check_var('peerreview_login_badge_submode','unlogged'),
      );
      
      $form['fixed_bar']['fixed_bar_unlogged']['fixed_bar_unlogged_element_' . $bar_unlogged_element]['peerreview_login_fixed_bar_unlogged_element_' . $bar_unlogged_element . '_link'] = array(
        '#type' => 'select',
        '#title' => t('Link option'),
        '#options' => array('default'=>t('default'),'disable'=>t('Disbaled')),
        '#description' => t(''),
        '#default_value' => variable_get('peerreview_login_fixed_bar_logged_element_' . $bar_logged_element . '_link', 0),
        '#disabled'=>_prl_check_var('peerreview_login_badge_submode','unlogged'),
      );
    }
  }

  return system_settings_form($form);
}


function _prl_check_var($variable,$key) {
  $vars=variable_get($variable,'');
    if(!($vars[$key]=='0')) {
      return FALSE;
    } elseif ($vars[$key]== '0') {
      return TRUE;
    }
}

function _prl_check_element_list($ask){
$element=(_prl_get_element('all',$ask));

$key_element = array_keys($element);
  foreach($key_element as $key){
    $out[$key]=$key;
  }
return $out;   
}
