#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMessage(const char *message) {
    printf("%s\n", message);
}

int main() {
    char *ptr = NULL;
    const char defaultMessage[] = "Default message";

    if (ptr == NULL) {
        ptr = strdup(defaultMessage);
        if (ptr == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    printMessage(ptr);
    free(ptr);
    return 0;
}