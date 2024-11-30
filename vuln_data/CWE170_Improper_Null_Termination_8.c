#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void copyString(const char *source) {
    char buffer[BUFFER_SIZE];
    strncpy(buffer, source, BUFFER_SIZE - 1);
    buffer[BUFFER_SIZE - 1] = '\0';
    printf("%s\n", buffer);
}

int main() {
    const char *input = "This is a test string that is too long.";
    copyString(input);
    return 0;
}