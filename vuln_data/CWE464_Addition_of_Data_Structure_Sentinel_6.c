#include <stdio.h>
#include <string.h>

void processString(char *input) {
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\0') {
        printf("Error: String contains unexpected null terminator at the end.\n");
        return;
    }

    char buffer[10];
    if (len >= sizeof(buffer)) {
        printf("Error: Input string too large.\n");
        return;
    }

    strcpy(buffer, input);
    printf("Processed string: %s\n", buffer);
}

int main() {
    char input[20];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    processString(input);
    return 0;
}