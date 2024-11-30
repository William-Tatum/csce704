#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerableFunction() {
    char *chunk1 = (char *)malloc(50);
    char *chunk2 = (char *)malloc(50);
    strcpy(chunk1, "Hello, world!");
    strcpy(chunk2, "Goodbye, world!");
    ptrdiff_t difference = chunk2 - chunk1;
    printf("Difference: %td\n", difference);
    free(chunk1);
    free(chunk2);
}

int main() {
    vulnerableFunction();
    return 0;
}