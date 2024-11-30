#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(const char *input) {
    char *buffer = malloc(256);
    
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    if (input != NULL && strlen(input) < 256) {
        strcpy(buffer, input);
        printf("Processed data: %s\n", buffer);
    } else {
        printf("Input data is invalid or too large\n");
    }

    free(buffer);
}

int main() {
    const char *data = "Sample data for processing";
    processData(data);

    return 0;
}