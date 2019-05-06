<?php
/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.
*/

// has to start with >= 2 digits, allowed 1 leading 0
$div2 = range(12, 999, 2);
$div3 = range(12, 999, 3);
$div4 = range(15, 999, 5);
$div5 = range(14, 999, 7);
$div6 = range(11, 999, 11);
$div7 = range(13, 999, 13);
$div8 = range(17, 999, 17);

$ans = [];

foreach($div2 as $d2){
  if($d2 < 100){
    $d2 = '0' . $d2;
  }
  $test = str_split($d2);
  if(array_unique($test) != $test){
    continue;
  }
  foreach($div3 as $d3){
    $test = str_split($d2);
    if($d3 < 100){
      $d3 = '0' . $d3;
    }
    if(substr($d3, 0, 2) != substr($d2, 1, 2)){
      continue;
    }
    if(in_array(substr($d3, 2, 1), $test)){
      continue;
    }
    $test[] = substr($d3, 2, 1);
    foreach($div4 as $d4){
      $test = array_merge(str_split($d2), array(substr($d3, 2, 1)));
      if($d4 < 100){
        $d4 = '0' . $d4;
      }
      if(substr($d4, 0, 2) != substr(implode($test), -2, 2)){
        continue;
      }
      if(in_array(substr($d4, 2, 1), $test)){
        continue;
      }
      $test[] = substr($d4, 2, 1);
      foreach($div5 as $d5){
        $test = array_merge(str_split($d2), array(substr($d3, 2, 1), substr($d4, 2, 1)));
        if($d5 < 100){
          $d5 = '0' . $d5;
        }
        if(substr($d5, 0, 2) != substr(implode($test), -2, 2)){
          continue;
        }
        if(in_array(substr($d5, 2, 1), $test)){
          continue;
        }
        $test[] = substr($d5, 2, 1);
        foreach($div6 as $d6){
          $test = array_merge(str_split($d2), array(substr($d3, 2, 1), substr($d4, 2, 1), substr($d5, 2, 1)));
          if($d6 < 100){
            $d6 = '0' . $d6;
          }
          if(substr($d6, 0, 2) != substr(implode($test), -2, 2)){
            continue;
          }
          if(in_array(substr($d6, 2, 1), $test)){
            continue;
          }
          $test[] = substr($d6, 2, 1);
          foreach($div7 as $d7){
            $test = array_merge(str_split($d2), array(substr($d3, 2, 1), substr($d4, 2, 1), substr($d5, 2, 1), substr($d6, 2, 1)));
            if($d7 < 100){
              $d7 = '0' . $d7;
            }
            if(substr($d7, 0, 2) != substr(implode($test), -2, 2)){
              continue;
            }
            if(in_array(substr($d7, 2, 1), $test)){
              continue;
            }
            $test[] = substr($d7, 2, 1);
            foreach($div8 as $d8){
              $test = array_merge(str_split($d2), array(substr($d3, 2, 1), substr($d4, 2, 1), substr($d5, 2, 1), substr($d6, 2, 1), substr($d7, 2, 1)));
              if($d8 < 100){
                $d8 = '0' . $d8;
              }
              if(substr($d8, 0, 2) != substr(implode($test), -2, 2)){
                continue;
              }
              if(in_array(substr($d8, 2, 1), $test)){
                continue;
              }
              $ans[] = implode($test) . substr($d8, 2, 1);
            }
          }
        }
      }
    }
  }
}
echo print_r($ans, true);
