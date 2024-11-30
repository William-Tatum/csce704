#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *input = "TooLongInputString";

    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    printf("Buffer contains: %s\n", buffer);
    return 0;
}