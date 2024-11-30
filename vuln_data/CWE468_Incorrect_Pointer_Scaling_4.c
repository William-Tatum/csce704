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
    ptr = ptr + 2; // Moves the pointer forward by 2 elements
    printf("Value at third position: %d\n", *ptr);
    
    void *void_ptr = array;
    // Incorrect pointer scaling due to using a void pointer
    void_ptr = void_ptr + 2; // Moves the pointer forward by 2 bytes, not elements
    printf("Incorrect value due to void pointer scaling: %d\n", *(int *)void_ptr);
    
    free(array);
    return 0;
}