//Sum all even fibonacci numbers not exceeding 4,000,000
#include <iostream>

int main(){
    int total = 0;
    int fib0 = 1;
    int fib1 = 1;
    int tempFib = 0;
    int limit = 4000000;
    for( int i = 0; fib1 < limit; i++ ){
        tempFib = fib1;
        fib1 += fib0;
        fib0 = tempFib;
        if( fib1 % 2 == 0 ){
            total += fib1;
        }
    }
    std::cout << "The sum of all even fibonacci numbers not exceeding " << limit << " is " << total << std::endl;
}
