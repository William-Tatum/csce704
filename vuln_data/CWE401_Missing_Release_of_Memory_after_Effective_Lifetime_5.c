#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(const char *data) {
    char *buffer = (char *)malloc(256);
    if (buffer == NULL) {
        return;
    }
    strncpy(buffer, data, 255);
    buffer[255] = '\0';
    printf("Processed data: %s\n", buffer);
    free(buffer);
}

int main() {
    const char *input = "Sample data";
    processData(input);
    return 0;
}