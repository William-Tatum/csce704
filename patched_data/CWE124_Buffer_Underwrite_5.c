#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE + 1]; // +1 for null terminator

    strncpy(buffer, "HelloWorld", BUFFER_SIZE);
    buffer[BUFFER_SIZE] = '\0';  // Ensure null terminator

    printf("Buffer content: %s\n", buffer);
    return 0;
}