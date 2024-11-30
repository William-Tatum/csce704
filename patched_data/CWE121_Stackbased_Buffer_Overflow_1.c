#include <stdio.h>
#include <string.h>

void secure_function(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Input: %s\n", buffer);
}

int main() {
    char large_input[] = "This is a very long input that will overflow the buffer";
    secure_function(large_input);
    return 0;
}