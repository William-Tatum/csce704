#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *source = "This is a string that is too long.";

    strncpy(buffer, source, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    printf("Buffer content: %s\n", buffer);
    return 0;
}