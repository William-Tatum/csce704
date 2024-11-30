#include <stdio.h>
#include <string.h>

void secure_function(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char large_input[50];
    memset(large_input, 'A', 49);
    large_input[49] = '\0';
    secure_function(large_input);
    return 0;
}