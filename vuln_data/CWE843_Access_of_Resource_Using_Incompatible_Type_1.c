#include <stdio.h>
#include <stdlib.h>

int main() {
    int *int_ptr;
    double *double_ptr;
    int_ptr = (int*) malloc(sizeof(int));
    if (int_ptr == NULL) {
        return 1;
    }

    *int_ptr = 42;
    double_ptr = (double*) int_ptr;

    printf("Value as int: %d\n", *int_ptr);
    printf("Value as double: %lf\n", *double_ptr);

    free(int_ptr);
    return 0;
}