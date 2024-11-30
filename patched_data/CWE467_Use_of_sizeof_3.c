#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(const char *source) {
    if (source == NULL) {
        printf("Invalid source string\n");
        return;
    }

    size_t length = strlen(source);
    char *destination = (char *)malloc(length + 1);
    if (destination == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    strncpy(destination, source, length);
    destination[length] = '\0'; 

    printf("Copied string: %s\n", destination);

    free(destination);
}

int main() {
    const char *original = "Hello, World!";
    copyString(original);
    return 0;
}