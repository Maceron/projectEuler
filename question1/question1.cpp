// Find the sum of all the multiples of 3 or 5 below 1000.
#include <iostream>

int main(){
    const int factor1 = 3;
    const int factor2 = 5;
    const int limit = 1000;
    int total = 0;
    for(int i = 0; i < limit; i++){
        if( i % 3 == 0 || i % 5 == 0 ){
            total += i;
        }
    }
    std::cout << "The sum of all numbers under " << limit << " that are divisible by " << factor1 << " or " << factor2 << " is " << total << std::endl;
    return 0;
}
