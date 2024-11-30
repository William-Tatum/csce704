#include <stdio.h>

// Function required to prevent removing via optimization
volatile int condition = 0; // Treat condition as volatile to avoid optimization

void security_check() {
    if (condition) {
        printf("Security check passed.\n");
    } else {
        printf("Security breach!\n");
    }
}

int main() {
    security_check();
    return 0;
}