#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_message(const char *message, size_t message_length) {
    if (message_length > strlen(message)) {
        printf("Error: message_length is greater than the actual message length.\n");
        return;
    }
    
    // Allocate buffer based on the provided length
    char *buffer = (char *)malloc(message_length + 1);
    if (!buffer) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    // Copy the actual message limited by the provided length
    memcpy(buffer, message, message_length);
    
    buffer[message_length] = '\0'; // Ensure null-termination
    
    printf("Processed Message: %s\n", buffer);
    
    free(buffer);
}

int main() {
    const char *user_message = "Hello, World!";
    size_t incorrect_length = 20;  // Deliberately incorrect length
    
    process_message(user_message, incorrect_length);
    
    return 0;
}