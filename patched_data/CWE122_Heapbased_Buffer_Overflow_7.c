#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safe_function(const char *input) {
    size_t input_length = strlen(input);
    char *heap_buffer = (char *)malloc((input_length + 1) * sizeof(char));
    if (heap_buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(heap_buffer, input, input_length);
    heap_buffer[input_length] = '\0';
    printf("Buffer content: %s\n", heap_buffer);
    free(heap_buffer);
}

int main() {
    char user_input[20];
    printf("Enter some text: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        user_input[strcspn(user_input, "\n")] = '\0';
        safe_function(user_input);
    } else {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    return 0;
}