#include <stdio.h>

int main() {
    int value = 0;
    int number = 10;

    // Correct: Using assignment
    value = number;

    if (value == number) {
        printf("Value is equal to number now.\n");
    }
    
    return 0;
}