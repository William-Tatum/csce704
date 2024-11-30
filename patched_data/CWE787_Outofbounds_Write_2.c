#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    const char *input = "This input is too long for the buffer.";

    strncpy(buffer, input, BUFFER_SIZE - 1);
    buffer[BUFFER_SIZE - 1] = '\0';

    printf("Buffer content: %s\n", buffer);

    return 0;
}