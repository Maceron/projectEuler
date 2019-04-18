<?php
/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

$pairs = array();

for($n = 11; $n < 100; $n++){
  if($n % 10 == 0 || substr($n,0,1) == substr($n,1,1)){
    continue;
  }
  for($d = $n + 1; $d < 100; $d++){
    if($d % 10 == 0 || substr($d,0,1) == substr($d,1,1)){
      continue;
    }
    if(substr($n,0,1) == substr($d,0,1)){
      if($n / $d == substr($n,1,1) / substr($d,1,1)){
        $pairs[] = array($n, $d);
      }
    }
    if(substr($n,0,1) == substr($d,1,1)){
      if($n / $d == substr($n,1,1) / substr($d,0,1)){
        $pairs[] = array($n, $d);
      }
    }
    if(substr($n,1,1) == substr($d,0,1)){
      if($n / $d == substr($n,0,1) / substr($d,1,1)){
        $pairs[] = array($n, $d);
      }
    }
    if(substr($n,1,1) == substr($d,1,1)){
      if($n / $d == substr($n,0,1) / substr($d,0,1)){
        $pairs[] = array($n, $d);
      }
    }
  }
}

$n = 1;
$d = 1;
foreach($pairs as $p){
  print("{$p[0]}/{$p[1]}\n");
  $n *= $p[0];
  $d *= $p[1];
}
print("\nProduct of fractions = {$n}/{$d}\n");

?>
