// find the sum of all the primes below 2 million
#include <iostream>
#include <cstdint>

int main(){
    uint64_t sum = 2;
    bool no = 0;
    for( int i = 3; i < 2000000; i += 2 ){
        no = 0;
        for( int j = 3; j <= i/j; j++ ){
            if( i % j == 0 ){
                no = 1;
                break;
            }
        }
        if( !no ){
//           std::cout << i << std::endl;
            sum += i;
        }
    }
    std::cout << std::endl << "sum of all primes <2000000 is " << sum << std::endl;  
    return 0;
}
