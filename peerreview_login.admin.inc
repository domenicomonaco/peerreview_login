<?php
// $Id$

/**
 * 
 * @file
 * Domenico Monaco / info@kiuz.it / www.kiuz.it
 */


/**
 * Area amministrativa
 * Mostra la login e le informazioni utente in un blocco al top della pagina (checkbox)

(se la precedente checkbox è spuntata attiva tutte le voci della domanda sottostante, altrimenti lasciale grigie, inattive)
Scegli quali informazioni mostrare:

    * Reputation (se attivo modulo user_karma) (checkbox)
    * Avatar (checkbox)
    * Button Aggiuntivi non previsti, è utile prevedere l'estendibilità della barra (PROPOSTA)
    * Pulsante che ritorna al "topAcor" nella pagina corrente (in funzione)
    * Pulsante torna alla Home (in funzione)
    * Ora corrente (in funzione)
    * Edit Profile (in funzione)
    * Pulsante Wizard (in via di svilupp) = Pulsante jolly: Se loggato mostra finestra animata con informazioni a vostra scelta, se non loggati mostra Finestra di Login sempre con animazione slide;
    
    Utili funzioni che possiamo aggiungere per rendere appetibile il modulo
    + Possibilità di ordinare gli elementi;
    + Possibilità di aggiugere elementi in modo custom;
    + Uso delle icone, le icone dovranno avere lo stesso nome della variabile in questo modo se si aggiunge una nuova variabile custom sapppiamo già in anticipo quale nome dovrà a avere la sua rispettiva icona;
    + Possibilità di un form di ricerca nella barra;
    + Strutturazione dei Div sufficentemente "elastica" da poter essere editata via Css e dare un aspetto accattivante al badge;

Mostra le informazioni dell'utente loggato in overlay (checkbox)
Lato utente¶

Utilizza i controlli sulle variabili che setti tramite l'area amministrativa per visualizzare in determinate posizioni i blocchi.
Tieni di default il seguente ordine quando estrai i dati:

Avatar - Nickname(cliccabile) - Reputation - Campo1 - Campo2 - Campo3

**/
function peerreview_login_setting() {

  $opt_mode=array(
  'enable'=>t('Enable'),
  );
  
  $nf_mode='peerreview_login_badge_mode';
  $form[$nf_mode] = array(
    '#type' => 'checkboxes',
    '#title' => 'Utilizza il badge dopo il login',
    '#options' => $opt_mode,
    '#default_value' => variable_get($nf_mode, ''),
    '#description' => '',    
  );
  
  $opt_submode=array(
  'logged'=>t('View logged user'),
  'unlogged'=>t('View unlogged users')
  );
  
  $nf_submode='peerreview_login_badge_submode';
  $form[$nf_submode] = array(
    '#type' => 'checkboxes',
    '#title' => 'Utilizza il badge dopo il login',
    '#options' => $opt_submode,
    '#default_value' => variable_get($nf_submode, ''),
    '#description' => '',
  );
  
  $peerreview_bh='peerreview_login_bar_height';
  $form[$peerreview_bh] = array(
  '#type' => 'textfield',
  '#title' => t('Height'),
  '#default_value' => variable_get($peerreview_bh, ''),
  '#size' => 5,
  '#maxlength' => 4,
  '#disabled'=>_peerreview_settingavaliable(''),
  '#description' => t('Inserisci l\'altezza massima che devono possedere le icone nel badge. Vincolerà solo la dimensione delle icone in altezza non in larghezza. Inserire la dimensione in pixel comprensivo della dicitura "px", es. "48px"')
  );
  
  
  
$opt_buttons=array(
  'wizard'=>t('Wizard Button'),
  'homelink'=>t('Home Link'),
  'topancor'=>t('Link to top Ancor'),
  'avatar'=>t('Avatar'),
  'username'=>t('Nick Name'),
  'setting'=>t('Edit Profile'),
  'karma'=>t('karma'),
  'email'=>t('e-mail'),
  'currentimestamp'=>t('Current timestamp'),
  'search'=>t('Serach Form')
);
$nf_buttons='peerreview_login_buttons';
$form[$nf_buttons] = array(
  '#type' => 'checkboxes',
  '#title' => 'Utilizza il badge dopo il login',
  '#options' => $opt_buttons,
  '#default_value' => variable_get($nf_buttons, ''),
  '#disabled'=>_peerreview_settingavaliable(''),
  '#description' => '',
);


/**
  * This section is largely copied from block.admin.inc.
  */
  $form['peerreview_login_wizard_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Wizard Button specific visibility settings'),
    '#collapsible' => TRUE, 
    
  );
  $form['peerreview_login_wizard_options']['peerreview_login_wizard_logged_content'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Logged User'),
    '#options' => array(
      'avatar'=>t('Avatar'),
      'email'=>t('E-mail'),
      'memberfrom'=>t('Member from ...'),
      'lastlogin'=>t('Last login'),
      'search'=>'Serach form'),
    '#disabled'=>_peerreview_settingavaliable('peerreview_login_wizard_logged_content'),
    '#description' => t('Allow individual users to customize the visibility of the appbar in their account settings.'),
    '#default_value' => variable_get('peerreview_login_wizard_logged_content', 0),
  );
    $form['peerreview_login_wizard_options']['peerreview_login_wizard_unlogged_content'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Unlogged User'),
    '#options' => array(
      'loginform'=>t('User Login Form'),
    ),
    '#disabled'=>_peerreview_settingavaliable('peerreview_login_wizard_logged_content'),
    '#description' => t(''),
    '#default_value' => variable_get('peerreview_login_wizard_unlogged_content', ''),
  );
  
  
  
  $form['peerreview_login_single_button_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Single button options'),
    '#collapsible' => TRUE, 
  );
 $form['peerreview_login_single_button_options']['peerreview_login_option_avatar'] = array(
    '#type' => 'select',
    '#title' => t('Avatar'),
    '#options' => array(
      'default'=>t('Default'),
      'linkprofile'=>t('Link to Prifile'),
      ),
    //'#disabled'=>_peerreview_settingavaliable('peerreview_login_wizard_logged_content'),
    //'#description' => t('Allow individual users to customize the visibility of the appbar in their account settings.'),
    '#default_value' => variable_get('peerreview_login_option_avatar', 0),
  );  
  
  
  
  
  return system_settings_form($form);
}


function _peerreview_settingavaliable($in){
$var=variable_get('peerreview_login_badge_mode','');

if($in=='peerreview_login_wizard_logged_content'){
  $var=variable_get('peerreview_login_buttons','');
  if(!($var['wizard']=='0')){
return false;
}
else if($var['wizard']=='0'){
return true;
}
}
if(!($var['enable']=='0')){
return false;
}
else if($var['enable']=='0'){
return true;
}

}
