#include <stdio.h>

int main() {
    int a = 0;
    int b = 5;
    
    if (a == b) {
        printf("a is equal to b\n");
    } else {
        printf("a is not equal to b\n");
    }

    // Incorrect use of comparison instead of assignment
    if (a = b) {
        printf("This won't behave as expected\n");
    }
    
    return 0;
}