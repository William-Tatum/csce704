#include <stdio.h>
#include <string.h>

void secureFunction(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char longInput[] = "ThisIsAVeryLongInputStringThatExceedsBuffer";
    secureFunction(longInput);
    return 0;
}