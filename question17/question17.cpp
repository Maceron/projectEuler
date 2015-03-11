// sum the characters of the english word of counting 1->1000 ('one' + 'two' .... 'one hundred and seven' ... + 'one thousand'
// ignore whitespace and hyphens, include "and" (according to british dictionary?)
#include <iostream>
#include <string>
using namespace std;

int main(){
    int charSum = 0;
    
    int one = 3;
    int two = 3;
    int three = 5;
    int four = 4;
    int five = 4;
    int six = 3;
    int seven = 5;
    int eight = 5;
    int nine = 4;
    int oneTOnine = one + two + three + four + five + six + seven + eight + nine;
    
    int ten = 3;

    int eleven = 6;
    int twelve = 6;
    int thirteen = 8;
    int fourteen = 8;
    int fifteen = 7;
    int sixteen = 7;
    int seventeen = 9;
    int eighteen = 8;
    int nineteen = 8;
    int elevenTOnineteen = eleven + twelve + thirteen + fourteen + fifteen + sixteen + seventeen + eighteen + nineteen;
    
    int twenty = 6;
    int thirty = 6;
    int forty = 5;
    int fifty = 5;
    int sixty = 5;
    int seventy = 7;
    int eighty = 6;
    int ninety = 6;
    
    int hundred = 7;
    int And = 3;
    int thousand = 8;
    
    // let's try it
    charSum = 900 * ( hundred ) + 190 * ( oneTOnine ) + 100 * ( twenty + thirty + forty + fifty + sixty + seventy + eighty\
     + ninety ) + 10 * ( ten ) + 10 * ( elevenTOnineteen ) + 99 * 9 * ( And ) + one + thousand;

    cout << charSum << endl;

    return 0;
}
