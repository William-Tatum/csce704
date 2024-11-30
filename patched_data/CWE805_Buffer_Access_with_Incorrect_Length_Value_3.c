#include <stdio.h>
#include <string.h>

void copy_buffer(char *source, size_t length) {
    char destination[10];
    if (length >= sizeof(destination)) {
        printf("Error: Length exceeds buffer size\n");
        return;
    }
    strncpy(destination, source, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';
    printf("Copied data: %s\n", destination);
}

int main() {
    char *data = "This string is too long for the buffer";
    size_t length = strlen(data);
    copy_buffer(data, length);
    return 0;
}