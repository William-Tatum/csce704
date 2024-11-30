#include <stdio.h>

int main() {
    int uninitialized_var = 0;
    if (uninitialized_var > 0) {
        printf("Variable is greater than zero.\n");
    } else {
        printf("Variable is less than or equal to zero.\n");
    }
    return 0;
}