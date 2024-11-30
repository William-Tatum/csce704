#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(const char *source) {
    size_t len = strlen(source);
    char *buffer = (char *)malloc(len); // Incorrect size calculation
    if (buffer != NULL) {
        strcpy(buffer, source); // Potential buffer overflow
        printf("Copied string: %s\n", buffer);
        free(buffer);
    } else {
        printf("Memory allocation failed\n");
    }
}

int main() {
    const char *exampleString = "Example";
    copyString(exampleString);
    return 0;
}