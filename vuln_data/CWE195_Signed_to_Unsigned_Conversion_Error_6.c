#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyData() {
    int size = -1;
    char source[10] = "123456789";
    char* destination;

    if (size < 0) {
        fprintf(stderr, "Invalid size\n");
        return;
    }

    destination = (char*)malloc((size_t)size);
    if (destination == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    memcpy(destination, source, (size_t)size);
    free(destination);
}

int main() {
    copyData();
    return 0;
}