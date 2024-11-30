#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safe_copy(const char *input) {
    size_t buffer_size = 11; // 10 characters + 1 for null terminator
    char *buffer = (char *)malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strncpy(buffer, input, buffer_size - 1);
    buffer[buffer_size - 1] = '\0'; // Ensure null termination
    printf("Buffer contents: %s\n", buffer);
    free(buffer);
}

int main() {
    char user_input[30];
    printf("Enter text: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        user_input[strcspn(user_input, "\n")] = '\0'; // Remove newline character
        safe_copy(user_input);
    }
    return 0;
}