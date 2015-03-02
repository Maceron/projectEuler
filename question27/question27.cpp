// For n^2 + a*n + b, find the product a*b, for the quadratic experession that produces the maximum number of primes for consecutive values of n, starting with n = 0, for |a| < 1000, |b| < 1000

#include <iostream>
using namespace std;

bool isPrime( int num ){
    if( num < 2 ){
        return 0;
    }
    if( num == 2 ){
        return 1;
    }
    for( int i = 3; i < ( num / i ); i += 2 ){
        if( num % i == 0 ){
            return 0;
        }
    }
    return 1;
}


int main(){
    // declare and set initial cases
    int a, b, n, count, answer, answerA, answerB, answerN;
    a = -999;
    b = -999;
    n = 0;
    answer = 0;
    answerA = 0;
    answerB = 0;
    
    while( a < 1000 ){
        while( b < 1000 ){
            n = 0;
            while ( isPrime( n*n + a*n + b ) ){
                count++;
                n++;           
            }
            if( count > answer ){
                answer = count;
                answerA = a;
                answerB = b;
                answerN = n;
            }
            count = 0;
            b++;
        }
        b = -999;
        //progress tracker if needed
        //cout << a << endl;
        a++;
    }
    cout << "With a = " << answerA << ", b = " << answerB << ", and their product = " << answerA * answerB <<\
     ", the quadratic expression produces " <<
    answer << " consecutive primes." << endl; 
    return 0;
}
