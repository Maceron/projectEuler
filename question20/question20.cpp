// find the sum of the digits in the number 1000!
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
    for( int i = 0; i < 1000; i++ ){
        if( array[i] != 0 ){
            start = i;
            break;
        }
    }

    for( int i = 0; i < 1000 - start + 1; i++ ){
        sum = ( array[999-i] + tempArray[999-i] + bonus );
        diff = sum % 10;
        bonus = ( sum - diff ) / 10;
        array[999-i] = diff;
    }

    return array;
}



int main(){
    int numToFact = 0;
    int answerArray[1000] = {0};
    int tempAnswerArray[1000] = {0};
    char temp[10] = {0};
    int lengthOfNum = 0;
    int answerStartIndex = 0;
    int sum = 0;
    int *temp2Array; 

    // take input as int, make a copy of it as a cstring (char array)
    cout << "number to factorial then sum digits?  ";
    cin >> numToFact;
    snprintf( temp, 10, "%d", numToFact);
     
    // count size of number to Factorial
    while( temp[lengthOfNum] != 0 ){
        lengthOfNum ++;
    }
    
    // copy number over into Int array to start solution
    for( int i = 999; i > 999 - lengthOfNum; i-- ){
        answerArray[i] = (temp[lengthOfNum - 1 - (999-i)] - '0');
    }

    for( int i = numToFact - 1; i > 1; i-- ){
        for( int c = 0; c < 1000; c++ ){
            tempAnswerArray[c] = answerArray[c];
        } 
        
        for( int j = i - 1; j > 0; j-- ){
            temp2Array = addThem( answerArray, tempAnswerArray );
            for( int c = 0; c < 1000; c++ ){
                answerArray[c] = temp2Array[c];
            }
        }
    }
   
    while( answerArray[answerStartIndex] == 0 ){
        answerStartIndex++;
    }

    for( int i = answerStartIndex; i < 1000; i++ ){
        sum += answerArray[i];
        cout << answerArray[i];
    }
    
    cout << endl << "the sum of all the digits in this number is:  " << sum << endl;

    return 0;
}

