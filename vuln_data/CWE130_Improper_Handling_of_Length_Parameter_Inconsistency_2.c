#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void process_message(char *message, size_t length) {
    char buffer[256];
    if (length > 256) {
        printf("Error: length exceeds buffer size\n");
        return;
    }
    strncpy(buffer, message, length);
    buffer[length] = '\0';
    printf("Processed message: %s\n", buffer);
}

int main() {
    char *input_message = "Hello, this is a sample message!";
    size_t length = strlen(input_message);
    process_message(input_message, length);
    return 0;
}