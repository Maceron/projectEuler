// a^2 + b^2 = c^2, where a < b < c.  a + b + c = 1000 is true for only one set of a,b,c. Find a*b*c.
#include <iostream>

int main(){
    int a = 1;
    int b = 1;
    int c = 1;
    for( int i = 1; i < 1000; i++  ){
        for( int j = 2; j < 1000; j++ ){
            for( int h = 3; h < 1000; h++ ){
                if( (i*i) + (j*j) == (h*h) ){
                    if( i + j + h == 1000 ){
                        std::cout << i << ", " << j << ", " << h << std::endl << i*j*h << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}
