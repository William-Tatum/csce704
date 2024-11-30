#include <stdio.h>
#include <string.h>

void safe_copy(const char *source, size_t length) {
    char buffer[10];
    if (length >= sizeof(buffer)) {
        printf("Error: Length exceeds buffer size\n");
        return;
    }
    strncpy(buffer, source, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination
    printf("Buffer content: %.*s\n", (int)length, buffer);
}

int main() {
    char input[] = "This is a long string";
    safe_copy(input, sizeof(input) - 1);
    return 0;
}