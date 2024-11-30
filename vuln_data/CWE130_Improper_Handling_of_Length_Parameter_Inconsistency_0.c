#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void processMessage(const char *message, unsigned int length) {
    char buffer[MAX_BUFFER_SIZE];
    if (length > MAX_BUFFER_SIZE - 1) {
        printf("Error: Length exceeds buffer size\n");
        return;
    }
    if (strlen(message) != length) {
        printf("Error: Length parameter is inconsistent with actual message length\n");
        return;
    }
    strncpy(buffer, message, length);
    buffer[length] = '\0';
    printf("Processed message: %s\n", buffer);
}

int main() {
    const char *msg = "Hello, world!";
    unsigned int length = 13;
    processMessage(msg, length);
    return 0;
}