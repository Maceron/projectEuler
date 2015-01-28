// Find the difference between (1^2 + 2^2 + 3^2 ... + 100^2)
// and (1 + 2 + 3 ... + 100)^2

#include <iostream>

int main(){
    int sum1 = 0;
    int sum2 = 0;
    for( int i = 1; i < 101; i++ ){
        sum1 += i*i;
        sum2 += i;
    }
    sum2 *= sum2;
    std::cout << "The answer is " << sum2-sum1 << std::endl;
    return 0;
}
