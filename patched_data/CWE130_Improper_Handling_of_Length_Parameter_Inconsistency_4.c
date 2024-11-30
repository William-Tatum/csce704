#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void process_message(const char* message) {
    char buffer[MAX_BUFFER_SIZE];
    size_t actual_length = strlen(message);

    if (actual_length >= MAX_BUFFER_SIZE) {
        printf("Error: Message length exceeds buffer size.\n");
        return;
    }

    strcpy(buffer, message);
    printf("Processed message: %s\n", buffer);
}

int main() {
    char msg[] = "Hello, world!";
    process_message(msg);
    return 0;
}