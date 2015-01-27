// Find the largest palindrom made from the product of two 3-digit numbers
#include <iostream>
#include <string>

bool isPalindrome(int num){
    std::string number = std::to_string(num);
    int length = number.length();
    //std::cout << length << std::endl;
    for( int i = 0; i <= (length / 2) - 1; i++ ){
        //std::cout << number[i] << "  vs   " << number[length-1-i] << std::endl;
        if( number[i] != number[length-1-i] ){
            return 0;
        }
    }
    return 1;
}


int main(){
    int answer = 0;
    int num1 = 0;
    int num2 = 0;
    int prod = 0;
    bool isPali = 0;
    //int testnum = 53235;
    //std::cout << isPalindrome(testnum) << std::endl;
    for( int i = 0; i < 1000; i++ ){
        for( int j = 0; j < 1000; j++ ){
            prod = i * j;
            isPali = isPalindrome(prod);
            if( isPali ){    
                if( prod > answer ){
                    answer = prod;
                    num1 = i;
                    num2 = j;
                }
            }
        }
    }
    std::cout << "The largest palindromic number formed from the product of two 3-digit numbers is  " << answer <<\
" formed from the product of " << num1 << " and  " << num2  << std::endl;
    return 0;
}
