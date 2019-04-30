<?php
/*
The decimal number, 585 = 1001001001[2] (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

function isPalindrome($str){
  // single digits are palindromes
  if($str < 10){
    return true;
  }
  for($i = 0; $i < (strlen($str) / 2) + 1; $i++){
    if(substr($str, $i, 1) != substr($str, strlen($str) - 1 - $i, 1)){
      return false;
    }
  }
  return true;
}

$sum = 0;
for($i = 1; $i < 1000000; $i++){
  if(isPalindrome((string)$i) && isPalindrome((string)decbin($i))){
    $sum += $i;
    echo "{$i} --- ".decbin($i)."\n";
  }
}
echo "\n{$sum}\n";
?>
