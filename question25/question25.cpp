// find n where fib(n) is the first fibonacci number with >1001 digits
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

// core method
int* addThem( int array[], int tempArray[] ){
    int start = 0;
    int sum = 0;
    int bonus = 0;
    int diff = 0;

    // find the start of the array
    for( int i = 0; i < 1001; i++ ){
        if( array[i] != 0 ){
            start = i;
            break;
        }
    }

    for( int i = 0; i < 1001 - start + 1; i++ ){
        sum = ( array[1000-i] + tempArray[1000-i] + bonus );
        diff = sum % 10;
        bonus = ( sum - diff ) / 10;
        array[1000-i] = diff;
    }

    return array;
}



int main(){
    int answerArray[1001] = {0};
    int tempAnswerArray[1001] = {0};
    int counter = 0;
    int temp2Array[1001]; 

    //fib(1) and fib(2) both = 1;
    answerArray[1000] = 1;
    tempAnswerArray[1000] = 1;

    //counter, starting at fib(3)
    counter = 2;
    
    while( answerArray[1] == 0 ){
        counter++;
        for( int i = 0; i < 1001; i++ ){
            temp2Array[i] = answerArray[i];
        }
        addThem( answerArray, tempAnswerArray );
        for( int i = 0; i < 1001; i++ ){
            tempAnswerArray[i] = temp2Array[i];
        }
    }
    
    for( int i = 0; i < 1001; i++ ){
        cout << answerArray[i];
    }
    cout << endl << "This is the " << counter << " fibonacci number" << endl;
    return 0;
}

