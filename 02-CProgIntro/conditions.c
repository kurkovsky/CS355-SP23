#include <stdio.h>

// Using conditions in C

int main(){
    int iAge = 0;
    printf("How old are you? ");
    
    // Read a value from the terminal and verify that 
    // it was interpreted correctly by scanf()
    int iReturnValue = scanf("%d", &iAge);
    if(iReturnValue != 1) {
        printf("scanf() could not interpret your input!\n");
        return 1;
    }
    
    printf("You told me that you are %d years old\n",iAge);

    return 0;
}