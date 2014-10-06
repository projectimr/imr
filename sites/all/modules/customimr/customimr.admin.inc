<?php



function profile_type_admin_settings_autocomplete($string) {
  $matches = array();
  $data_string = '';
  $stringArray = array();

  $stringArray = explode(',', $string);

  $result = db_select('profile_type', 'pt')->fields('pt', array('profile_type'))->condition('profile_type', db_like($stringArray[count($stringArray)-1]) .'%', 'LIKE')->range(0, 10)->execute()->fetchAll();
  if(count($stringArray)>1){
    unset($stringArray[count($stringArray)-1]);
    $data_string = implode(",", $stringArray);
    $data_string = $data_string.',';
  }
  foreach ($result as $data) {
    $matches[$data_string.$data->profile_type] = check_plain($data_string.$data->profile_type);
  }
  drupal_json_output($matches);
} 
