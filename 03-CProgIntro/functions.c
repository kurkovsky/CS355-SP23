#include <stdio.h>

// how to work with user-defined functions

// a straightforward implementation of a function that calculates the product of two integers
// both parameters are passed by value
int product(int x, int y){
    int tmp = x * y;
    return tmp;
}

int main(){
    int a=3, b=5;
    int tmp = product(a, b);
    printf("%d\n", tmp);
    return 0; 
}