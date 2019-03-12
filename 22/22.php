<?php
/*
  Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order.
  Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

  For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain
  a score of 938 × 53 = 49714.

  What is the total of all the name scores in the file?
*/

$csv = fopen('names.txt', 'r');
$names = fgetcsv($csv);
sort($names);
$total = 0;

$count = 1;
foreach($names as $n){
  $sum = 0;
  foreach(str_split($n) as $c){
    $sum += ord($c) - ord('A') + 1;
  }
  $total += $sum * $count;
  $count += 1;
}

print "{$total}\n";
