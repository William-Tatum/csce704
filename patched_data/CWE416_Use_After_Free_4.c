#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    *ptr = 50;
    
    // Safely handle the value before freeing
    printf("%d\n", *ptr);

    free(ptr);
    ptr = NULL; // Prevent use after free by nullifying the pointer

    // Subsequent allocation
    int *newPtr = (int *)malloc(sizeof(int));
    if (newPtr == NULL) {
        return 1;
    }
    
    *newPtr = 100;
    
    // Output for the new allocation, avoiding use of 'ptr'
    printf("%d\n", *newPtr);

    free(newPtr);
    newPtr = NULL; // Nullify pointer after freeing
    return 0;
}