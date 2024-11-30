#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secureFunction() {
    char *chunk1 = (char *)malloc(50);
    if (chunk1 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    char *chunk2 = (char *)malloc(50);
    if (chunk2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(chunk1);
        return;
    }
    strncpy(chunk1, "Hello, world!", 49);
    chunk1[49] = '\0';
    strncpy(chunk2, "Goodbye, world!", 49);
    chunk2[49] = '\0';
    ptrdiff_t difference = chunk2 - chunk1;
    printf("Difference: %td\n", difference);
    free(chunk1);
    free(chunk2);
}

int main() {
    secureFunction();
    return 0;
}