<?php
/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

$ans = [];
for($c = 2; $c < 999; $c++){
  for($a = 1; ($a < $c) && ($a + $b + $c < 1001); $a++){
    for($b = 1; ($b < $c) && ($a + $b + $c < 1001); $b++){
      if($a ** 2 + $b ** 2 == $c ** 2){
        $p = $a + $b + $c;
        $comb = array($a, $b, $c);
        sort($comb);
        if(!isset($ans[$p])){
          $ans[$p][] = $comb;
        }
        else if(!in_array($comb, $ans[$p])){
          $ans[$p][] = $comb;
        }
      }
    }
  }
}

$max = 0;
$res = 0;
foreach($ans as $k => $v){
  if(count($v) > $max){
    $max = count($v);
    $res = $k;
  }
}
echo print_r($ans[$res],true);
