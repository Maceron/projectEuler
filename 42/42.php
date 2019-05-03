<?php
/*
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/

$tnums = array();
for($i = 0; $i <= 50; $i++){
  $tnums[$i] = (0.5 * $i * ($i + 1));
}
$count = 0;
$f = file_get_contents('words.txt');
$f = str_replace('"', '', $f);
$f = explode(',', $f);

foreach($f as $word){
  $sum = 0;
  foreach(str_split($word) as $c){
    $sum += (ord($c) - ord('A') + 1);
  }
  if(in_array($sum, $tnums)){
    $count++;
    echo "{$word} sum is {$sum}\n";
  }
}

echo "\ntotal count = {$count}\n";
