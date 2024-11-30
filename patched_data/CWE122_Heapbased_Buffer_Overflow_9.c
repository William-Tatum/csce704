#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    buffer = malloc(50); // Increased buffer size to safely hold the string and null terminator

    if(buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    strncpy(buffer, "This string is too long for the buffer", 49); // Use strncpy for safe copying
    buffer[49] = '\0'; // Ensure null termination

    printf("Buffer: %s\n", buffer);

    free(buffer);
    return 0;
}