#include <stdio.h>

int main() {
    int *ptr;
    int variable = 10;

    ptr = &variable; // Set pointer to address of a variable
    if(ptr != NULL) {
        printf("Value: %d\n", *ptr);
    }

    return 0;
}