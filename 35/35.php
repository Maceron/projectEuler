<?php
/*
  The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

  There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

  How many circular primes are there below one million?
*/

function isPrime($n){
  if($n % 2 == 0){
    return false;
  }
  for($i = 3; $i <= ceil($n/$i); $i += 2){
    if($n % $i == 0){
      return false;
    }
  }
  return true;
}

// put 2 in the results already since we start search from 3
$c = array(2);
for($i = 3; $i < 1000000; $i += 2){
  if(!isPrime($i)){
    continue;
  }
  for($j = 1; $j < strlen($i); $j++){
    $newstr = substr($i, $j, strlen($i) - $j) . substr($i, 0, $j);
    if(!isPrime($newstr)){
      continue 2;
    }
  }
  $c[] = $i;
}

print(print_r($c,true)."\n");
