#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processInput(const char *input) {
    size_t length = strlen(input);
    
    // Allocate one extra byte for the null terminator
    char *buffer = (char *)malloc((length + 1) * sizeof(char));
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }
    
    strncpy(buffer, input, length);
    buffer[length] = '\0'; // Ensure null-termination
    printf("Processed input: %s\n", buffer);
    
    free(buffer);
}

int main() {
    char data[100];
    printf("Enter some text: ");
    if (fgets(data, sizeof(data), stdin) != NULL) {
        // Remove the newline character from fgets if present
        data[strcspn(data, "\n")] = '\0';
        processInput(data);
    }
    return 0;
}