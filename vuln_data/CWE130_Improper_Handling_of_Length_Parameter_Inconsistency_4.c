#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void process_message(char* message, unsigned int provided_length) {
    char buffer[MAX_BUFFER_SIZE];
    unsigned int actual_length = strlen(message);

    if (provided_length > MAX_BUFFER_SIZE || provided_length != actual_length) {
        printf("Error: Inconsistent length parameter.\n");
        return;
    }

    strncpy(buffer, message, provided_length);
    buffer[provided_length] = '\0';

    printf("Processed message: %s\n", buffer);
}

int main() {
    char msg[] = "Hello, world!";
    unsigned int length = 15; // Incorrect length provided intentionally
    process_message(msg, length);

    length = strlen(msg);
    process_message(msg, length);

    return 0;
}