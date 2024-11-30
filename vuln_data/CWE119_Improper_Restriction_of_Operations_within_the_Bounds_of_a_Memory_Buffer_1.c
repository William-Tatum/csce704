#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char longInput[] = "ThisIsAVeryLongInputStringThatExceedsBuffer";
    vulnerableFunction(longInput);
    return 0;
}