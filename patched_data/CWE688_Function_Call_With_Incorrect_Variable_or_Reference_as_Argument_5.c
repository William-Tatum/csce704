#include <stdio.h>

void updateValue(int *varToUpdate) {
    if (varToUpdate != NULL) {
        *varToUpdate = 50;
    }
}

int main() {
    int correctVar = 10;
    updateValue(&correctVar);
    printf("The value is: %d\n", correctVar);
    return 0;
}