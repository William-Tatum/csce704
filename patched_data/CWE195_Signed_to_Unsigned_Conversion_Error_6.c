#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyData() {
    size_t size = 10; // Fixed size to match the source array length
    char source[10] = "123456789";
    char* destination;

    destination = (char*)malloc(size);
    if (destination == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    memcpy(destination, source, size);
    free(destination);
}

int main() {
    copyData();
    return 0;
}