#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = malloc(5 * sizeof(int));
    if (array == NULL) {
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        array[i] = i;
    }
    int *ptr = array;
    ptr = ptr + 2;
    printf("Value at third position: %d\n", *ptr);
    
    int *int_ptr = array;
    int_ptr = int_ptr + 2;
    printf("Correct value using int pointer: %d\n", *int_ptr);
    
    free(array);
    return 0;
}