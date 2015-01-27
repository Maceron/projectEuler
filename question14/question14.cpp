// Which starting number (under one million) produces the longest chain of the Collatz sequence
// n -> n/2 (when n is even), n -> 3n + 1 (when odd)

#include <iostream>
#include <cstdint>

int collatz( uint64_t number ){
    int counter = 0;
    while( number != 1 ){
        if( number % 2 == 0 ){
            number /= 2;
        }
        else{
            number = number * 3 + 1;
        }
        counter++;
    }
    return counter;
}

int main(){
    int answer = 1;
    uint64_t result = 0;
    int length = 0;
    for( uint64_t i = 2; i < 1000000; i++ ){
        result = collatz(i);
        if( result > length ){
            answer = i;
            length = result;
        }
    }
    std::cout << "The number under one million that produces the longest Collatz chain is " << answer << " with a chain\
length of " << length << std::endl;
}
