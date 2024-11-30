#include <stdio.h>

void vulnerableFunction() {
    int uninitializedVar;
    if (uninitializedVar > 0) {
        printf("Variable is positive: %d\n", uninitializedVar);
    } else {
        printf("Variable is not positive or it is zero: %d\n", uninitializedVar);
    }
}

int main() {
    vulnerableFunction();
    return 0;
}