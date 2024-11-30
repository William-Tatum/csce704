#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_input(const char *input) {
    int input_length = strlen(input);
    char *buffer = (char *)malloc(input_length + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(buffer, input, input_length);
    buffer[input_length] = '\0'; 
    printf("Processed: %s\n", buffer);
    free(buffer);
}

int main() {
    const char *user_input = "This is a test";
    process_input(user_input);
    return 0;
}