// find the first triangle number with over 500 divisors
// the n-th triangle number is the sum of all integers 1->n inclusive.
#include <iostream>

int main(){
    int tNum = 0;
    int divs = 0;
    int element = 0;
    while( divs < 500 ){
        divs = 0;
        element ++;
        tNum = ( element * ( element - 1 ) ) / 2;
        for( int i = 1; i < tNum / i; i++ ){
            if( tNum % i == 0 ){
                divs += 2;
            }
            if( tNum / i == i ){
                divs++;
            }
        }
    }
    std::cout << std::endl << "The answer is " << tNum << std::endl;
    return 0;
}
