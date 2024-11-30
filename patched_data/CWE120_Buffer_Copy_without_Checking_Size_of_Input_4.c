#include <string.h>
#include <stdio.h>

void safe_copy(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char large_input[20] = "This is too long";
    safe_copy(large_input);
    return 0;
}