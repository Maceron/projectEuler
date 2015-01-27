// What is the smallest positive number that is evenly divisible (no remainder)
// by all the numbers from 1 to 20?

#include <iostream>
#include <cstdint>

int main(){
    int answer = 0;
    bool done = 0;
    uint64_t num = 0;
    while( done != 1 ){
        num += 20;
        for( int i = 19; i > 2; i-- ){
            if( num % i != 0 ){
                break;
            }
            if( i == 3 ){
                done = 1;
            }
        }
    }
    std::cout << "The smallest positive number that is evenly divisible by \
all the numbers from 1 to 20 is " << num << std::endl;
    return 0;
}


