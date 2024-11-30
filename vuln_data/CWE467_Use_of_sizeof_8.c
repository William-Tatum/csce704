#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *ptr = malloc(10 * sizeof(int));
    if (ptr == NULL) {
        return 1; 
    }
    
    printf("Size of allocated memory: %zu\n", sizeof(ptr));

    free(ptr);
    return 0;
}