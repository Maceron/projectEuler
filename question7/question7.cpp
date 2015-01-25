// What is the 10,001st prime number
#include <iostream>

int main(){
    int counter = 1;
    bool notprime = 0;
    int answer = 0;
    for( int i = 1; counter <= 1000000; i+=2 ){
        notprime = 0;
        for( int j = 2; j < ( i / 2 ); j++ ){
            if( i % j == 0 ){
                notprime = 1;
                break;
            }
        }
        if( notprime == 0 ){
            answer = i;
            counter++;
        }
    }
    std::cout << answer << std::endl;
}
