#include <stdio.h>

int main() {
    int a = 0;
    int b = 5;
    
    if (a == b) {
        printf("a is equal to b\n");
    } else {
        printf("a is not equal to b\n");
    }

    a = b; // Corrected assignment
    if (a == b) {
        printf("a is now equal to b after assignment\n");
    }
    
    return 0;
}