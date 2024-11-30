#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(const char *input) {
    char *buffer = (char *)malloc(256);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strncpy(buffer, input, 255);
    buffer[255] = '\0';

    printf("Processed data: %s\n", buffer);
    
    free(buffer);
}

int main() {
    const char *data = "Some input data";
    processData(data);
    return 0;
}