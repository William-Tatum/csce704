#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(const char *data) {
    if (data == NULL) {
        return;
    }
    size_t dataLen = strlen(data);
    char *buffer = (char *)malloc(dataLen + 1);
    if (buffer == NULL) {
        return;
    }
    strncpy(buffer, data, dataLen);
    buffer[dataLen] = '\0';
    printf("Processed data: %s\n", buffer);
    free(buffer);
}

int main() {
    const char *input = "Sample data";
    processData(input);
    return 0;
}