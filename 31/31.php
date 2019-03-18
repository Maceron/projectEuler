<?php
/*
  In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

  1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
  It is possible to make £2 in the following way:

  1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
  How many different ways can £2 be made using any number of coins?
*/

$goal = 200;
$coins = array(200, 100, 50, 20, 10, 5, 2, 1);
$count = 0;

function combinations($goal, $coins){
  $count = 0;
  foreach($coins as $c){
    for($i = floor($goal/$c); $i > 0; $i--){
      if($i * $c == $goal){
        $count++;
      }
      else{
        unset($coins[array_search($c, $coins)]);
        $count += combinations($goal - ($i * $c), $coins);
      }
    }
  }
  return $count;
}

print combinations($goal, $coins) . "\n";
