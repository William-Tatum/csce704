#include <stdio.h>
#include <string.h>

void vulnerableFunction(const char *source) {
    char buffer[10];
    strncpy(buffer, source, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
}

int main() {
    const char *input = "Very long input string";
    vulnerableFunction(input);
    return 0;
}