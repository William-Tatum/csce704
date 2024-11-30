#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copy_data(int size, char *src) {
    if (size <= 0) {
        printf("Error: Invalid size\n");
        return;
    }
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    memcpy(buffer, src, size > strlen(src) ? strlen(src) : size);
    printf("Data copied\n");
    free(buffer);
}

int get_size() {
    return -10; // Assume a function that accidentally returns negative size
}

int main() {
    int size = get_size();
    char data[] = "Example data";
    copy_data(size, data);
    return 0;
}