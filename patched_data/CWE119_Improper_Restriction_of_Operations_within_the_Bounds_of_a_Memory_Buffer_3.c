#include <stdio.h>
#include <string.h>

void safeFunction(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char *largeString = "This input string is definitely too large for the buffer";
    safeFunction(largeString);
    return 0;
}