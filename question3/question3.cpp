// Find the largest prime factor of 600,851,475,143
#include <iostream>
#include <cstdint>
#include <cmath>

bool isItAFactor(uint64_t smallNum, uint64_t bigNum){
    if(bigNum % smallNum == 0){
        return 1;
    }
    return 0;
}

bool isItPrime(uint64_t number){
    for( int i = 2; i < number/2; i++ ){
        if( number % i == 0 ){
            return 0;
        }
    }
    return 1;
}


int main(){
    uint64_t bigNumber = 600851475143;
    int rootOfBig = sqrt(bigNumber);
    std::cout << rootOfBig << std::endl;
    uint64_t answer = 0;
    uint64_t partner = 0;
    
    for( int i = 2; i <= rootOfBig; i++ ){
        if( isItAFactor(i,bigNumber) ){
            partner = bigNumber / i;
            if( isItPrime(i) && i > answer ){
                answer = i;
            }
            if( isItPrime(partner) ){
                if( partner > i && partner > answer ){
                    answer = partner;
                }
            }
        }
    }
     
    std::cout << "The largest prime factor of " << bigNumber << " is " <<  answer << std::endl;
    return 0;
}
