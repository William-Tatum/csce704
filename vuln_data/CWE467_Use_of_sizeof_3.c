#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(const char *source) {
    char *destination = (char *)malloc(strlen(source) + 1);
    if (destination == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    strcpy(destination, source);
    printf("Copied string: %s\n", destination);

    free(destination);
}

int main() {
    const char *original = "Hello, World!";
    copyString(original);
    return 0;
}