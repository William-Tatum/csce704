#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(char *input, size_t length) {
    char buffer[100];
    if (length > sizeof(buffer) - 1) {
        printf("Length parameter is inconsistent with buffer size.\n");
        return;
    }
    memcpy(buffer, input, length);
    buffer[length] = '\0';
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char data[] = "Example Data";
    size_t length = 200; // Incorrect length leading to potential overflow
    processData(data, length);
    return 0;
}