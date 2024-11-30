#include <stdio.h>
#include <stdlib.h>

void correct_pointer_subtraction() {
    char *buffer1 = malloc(50);
    char *buffer2 = malloc(100);
    if (buffer1 == NULL || buffer2 == NULL) {
        free(buffer1);
        free(buffer2);
        exit(1);
    }

    char *ptr1 = buffer1 + 10;
    char *ptr2 = buffer1 + 20;
    
    size_t size = ptr2 - ptr1;
    printf("Size: %zu\n", size);

    free(buffer1);
    free(buffer2);
}