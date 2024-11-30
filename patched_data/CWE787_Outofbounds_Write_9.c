#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *data = "This string is definitely too long for the buffer";

    strncpy(buffer, data, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    printf("Buffer contains: %s\n", buffer);
    return 0;
}