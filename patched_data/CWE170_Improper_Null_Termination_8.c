#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void copyString(const char *source) {
    char buffer[BUFFER_SIZE];
    if (snprintf(buffer, BUFFER_SIZE, "%s", source) < 0) {
        // Handle error
    }
    printf("%s\n", buffer);
}

int main() {
    const char *input = "This is a test string that is too long.";
    copyString(input);
    return 0;
}