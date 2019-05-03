<?php
/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/


/*
  After brute forcing a huge execution time, reading the answers thread revealed a cool trick for helping with this problem, and also checking primes

  if the sum of the digits of an integer is divisible by 3, then the integer is also divisible by 3

  this means we can check the sum of (1,2) (1,2,3) (1,2,3,4) etc.. and discover it has to be either (1,2,3,4) or (1,2,3,4,5,6,7)
*/
function isPrime($n){
  if($n % 2 == 0 || $n == 1){
    return false;
  }
  for($i = 3; $i <= ceil($n/$i); $i += 2){
    if($n % $i == 0){
      return false;
    }
  }
  return true;
}

// there must be a pandigital prime above 912,345,678 so skip the first 900,000,000
// also will have to be odd to be prime
for($i = 3; $i < 1E9; $i += 2){
  $test = str_split((string)$i);
  sort($test);
  if($test == range(1, ceil(log10($i)))){
    if(isPrime($i)){
      echo "{$i}\n";
    }
    else{
//      echo "{$i} is not prime\n";
    }
  }
}
