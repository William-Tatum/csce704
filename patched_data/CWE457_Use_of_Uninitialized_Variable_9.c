#include <stdio.h>

void safeFunction() {
    int initializedVar = 0; // Initialize variable to a default value
    if (initializedVar > 0) {
        printf("Variable is positive: %d\n", initializedVar);
    } else {
        printf("Variable is not positive or it is zero: %d\n", initializedVar);
    }
}

int main() {
    safeFunction();
    return 0;
}