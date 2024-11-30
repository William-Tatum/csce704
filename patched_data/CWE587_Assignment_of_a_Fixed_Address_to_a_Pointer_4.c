#include <stdio.h>

int main() {
    int *ptr = NULL;
    int variable = 10;

    ptr = &variable;
    if(ptr != NULL) {
        printf("Value: %d\n", *ptr);
    }

    return 0;
}