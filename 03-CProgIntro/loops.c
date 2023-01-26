#include <stdio.h>

// This example introduces three kinds of loops

int main(){
    int i = 0;          // a counter used in every loop

    // a while loop has a pre-condition that is checked before the body of the loop is executed each time
    while(i<10) {
        printf("%d ", i);   // prints values from 0 to 9 on a single line
        i++;
    }
    printf("\n");
    
    // a do/while loop has a post-condition that is checked after the body of the loop is executed each time
    do {
        printf("%d ", i);
        i++;
    } while(i<10);
    printf("\n");

    // a for loop has four components: an initialization, a condition, an increment, and a body
    for(i=0; i<10; i++){
        printf("%d ", i);
    }
    printf("\n");

    // display a triangle composed of asterisks
    // the number of asterisks on the line corresponds to the line number
    int line, star;
    for(line=1; line<=10; line++) {         // iterate over every line
        printf("%2d ", line);
        for(star=1; star<=line; star++) {   // iterate over every asterisk on the current line
            printf("*");
        }
        printf("\n");
    }
 //   printf("\n");

    return 0;
}