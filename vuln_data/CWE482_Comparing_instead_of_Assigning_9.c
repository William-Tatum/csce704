#include <stdio.h>

int main() {
    int value = 0;
    int input = 5;
    
    if (value == input) {
        printf("Value and input are equal.\n");
    }
    
    // Fix: the following line mistakenly uses '==' instead of '=' for assignment
    value = input;
    
    printf("Assigned value: %d\n", value);
    
    return 0;
}