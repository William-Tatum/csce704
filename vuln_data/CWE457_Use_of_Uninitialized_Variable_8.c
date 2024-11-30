#include <stdio.h>

int main() {
    int uninitialized_var;
    if (uninitialized_var > 0) {
        printf("Uninitialized variable is greater than zero.\n");
    } else {
        printf("Uninitialized variable is less than or equal to zero.\n");
    }
    return 0;
}