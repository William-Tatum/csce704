#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_message(const char *message, size_t message_length) {
    size_t actual_length = strlen(message);

    if (message_length > actual_length) {
        printf("Error: message_length is greater than the actual message length.\n");
        return;
    }

    char *buffer = (char *)malloc(actual_length + 1);
    if (!buffer) {
        printf("Memory allocation failed.\n");
        return;
    }

    memcpy(buffer, message, actual_length);
    buffer[actual_length] = '\0';

    printf("Processed Message: %s\n", buffer);

    free(buffer);
}

int main() {
    const char *user_message = "Hello, World!";
    size_t correct_length = strlen(user_message);

    process_message(user_message, correct_length);

    return 0;
}