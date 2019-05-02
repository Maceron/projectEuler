<?
/*
  The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

  Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

  NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

function isPrime($n, &$primes){
  if(in_array($n, $primes)){
    return true;
  }
  if($n % 2 == 0 || $n == 1){
    return false;
  }
  for($i = 3; $i <= ceil($n/$i); $i += 2){
    if($n % $i == 0){
      return false;
    }
  }
  $primes[] = $n;
  return true;
}

function truncatePrime($n, $d, &$primes){
  if($n < 10){
    if(in_array($n, array(2, 3, 5, 7))){
      return true;
    }
  }

  if(isPrime($n, $primes)){
    if($d == 'LEFT'){
      $new = substr($n, 1);
    }
    else{
      $new = substr($n, 0, -1);
    }
    return truncatePrime($new, $d, $primes);
  }
  return false;
}

$ans = [];
$primes = array(2, 3, 5, 7);
for($i = 11; count($ans) < 11; $i += 2){
  if(in_array((int)substr($i, 0, 1), array(1, 4, 6, 8, 9))){
    continue;
  }
  if(in_array((int)substr($i, -1, 1), array(1, 4, 6, 8, 9))){
    continue;
  }
  if(isPrime($i, $primes)){
    if(truncatePrime($i, 'LEFT', $primes) && truncatePrime($i, 'RIGHT', $primes)){
      echo "{$i}\n";
      $ans[] = $i;
    }
  }
}
