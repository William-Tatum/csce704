#include <stdio.h>
#include <string.h>

void copyBuffer(const char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Copied: %s\n", buffer);
}

int main() {
    char largeInput[] = "This is a very long input that exceeds buffer size";
    copyBuffer(largeInput);
    return 0;
}