#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(char *input, size_t length) {
    char buffer[100];
    size_t safeLength = length < sizeof(buffer) - 1 ? length : sizeof(buffer) - 1;
    memcpy(buffer, input, safeLength);
    buffer[safeLength] = '\0';
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char data[] = "Example Data";
    size_t length = strlen(data); // Correct length to prevent overflow
    processData(data, length);
    return 0;
}