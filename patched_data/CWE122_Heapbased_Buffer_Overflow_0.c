#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_function(const char *input) {
    size_t buffer_size = 10;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        exit(1);
    }
    strncpy(buffer, input, buffer_size - 1);
    buffer[buffer_size - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
    free(buffer);
}

int main() {
    char input[20] = "ThisIsTooLongForTheBuffer";
    secure_function(input);
    return 0;
}