#include <stdio.h>
#include <string.h>

void processString(char *input) {
    size_t len = strlen(input);
    char buffer[10];

    if (len >= sizeof(buffer)) {
        printf("Error: Input string too large.\n");
        return;
    }

    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    printf("Processed string: %s\n", buffer);
}

int main() {
    char input[20];
    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        processString(input);
    }
    return 0;
}