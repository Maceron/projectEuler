// find the sum of all the amicable numbers under 10,000.
// an pair of numbers A and B are amicable if the sum of the divisors of A (<= A) = B and vice versa.
#include <iostream>
using namespace std;

int sumOfFactors( int num ){
    int sum = 0;
    for( int i = 1; i <= num / 2; i++ ){
        if( num % i == 0 ){
            sum += i;
        }
    }
    return sum;
}

int main(){
    // store the amicable pairs for fun
    int pairs[20][2] = {0};
    int index = 0;
    int sumTotal = 0;
    
    int sum1 = 0;
    int sum2 = 0;
    for( int i = 1; i < 10000; i++ ){
        sum1 = sumOfFactors( i );
        sum2 = sumOfFactors( sum1 );
        //cout << i << " --- " << sum1 << "  vs  " << sum2 << endl;
        if( sum2 == i && i != sum1 ){
            pairs[index][0] = i;
            pairs[index][1] = sum1;
            sumTotal += i;
            index ++;
        }
    }
    
    for( int i = 0; i < 20; i++ ){
        cout << pairs[i][0] << "  and  " << pairs[i][1] << endl;
    }

    cout << sumTotal << endl;
    

    return 0;
}
