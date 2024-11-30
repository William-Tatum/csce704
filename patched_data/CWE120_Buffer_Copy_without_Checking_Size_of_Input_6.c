#include <stdio.h>
#include <string.h>

void safeFunction(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // ensure null-termination
    printf("Buffer contents: %s\n", buffer);
}

int main() {
    char input[20];
    printf("Enter input: ");
    if (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\n")] = 0;
        safeFunction(input);
    }
    return 0;
}