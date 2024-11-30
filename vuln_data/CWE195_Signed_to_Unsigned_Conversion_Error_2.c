#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fetch_data_size() {
    return -1;
}

int main() {
    int dataSize = fetch_data_size();
    if (dataSize < 0) {
        printf("Error: Negative size value returned\n");
        return 1;
    }

    unsigned int unsignedSize = (unsigned int)dataSize;

    char *buffer = (char *)malloc(unsignedSize);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    memset(buffer, 0, unsignedSize);

    free(buffer);
    return 0;
}