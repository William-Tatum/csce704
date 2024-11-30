#include <stdio.h>

int main() {
    int value = 0;
    int input = 5;
    
    if (value == input) {
        printf("Value and input are equal.\n");
    }
    
    value = input;
    
    printf("Assigned value: %d\n", value);
    
    return 0;
}