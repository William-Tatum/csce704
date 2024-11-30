#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void allocateMemory(int size) {
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size for memory allocation\n");
        return;
    }
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Memory allocated\n");
    free(buffer);
}

int main() {
    int size;
    printf("Enter size for memory allocation: ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    allocateMemory(size);
    return 0;
}