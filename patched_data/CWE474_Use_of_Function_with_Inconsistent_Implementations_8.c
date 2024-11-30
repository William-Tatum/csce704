#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50];
    printf("Enter a file path: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/._-";
        if (strspn(input, allowed_chars) != strlen(input)) {
            fprintf(stderr, "Invalid file path.\n");
            exit(EXIT_FAILURE);
        }

        FILE *file = fopen(input, "r");
        if (file == NULL) {
            fprintf(stderr, "Error opening file.\n");
            exit(EXIT_FAILURE);
        }

        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }

        fclose(file);
    } else {
        fprintf(stderr, "Input error.\n");
    }
    return 0;
}