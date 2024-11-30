#include <stdio.h>
#include <stdlib.h>

void incorrect_pointer_subtraction() {
    char *buffer1 = malloc(50);
    char *buffer2 = malloc(100);
    if (buffer1 == NULL || buffer2 == NULL) {
        exit(1);
    }

    char *ptr1 = buffer1 + 10;
    char *ptr2 = buffer2 + 20;
    
    size_t size = ptr1 - ptr2;
    printf("Size: %zu\n", size);

    free(buffer1);
    free(buffer2);
}