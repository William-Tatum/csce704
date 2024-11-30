#include <stdio.h>
#include <string.h>

void copyBuffer(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Copied: %s\n", buffer);
}

int main() {
    char largeInput[] = "This is a very long input that exceeds buffer size";
    copyBuffer(largeInput);
    return 0;
}