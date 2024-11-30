#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(const char *source) {
    size_t len = strlen(source) + 1;
    char *buffer = (char *)malloc(len);
    if (buffer != NULL) {
        strncpy(buffer, source, len);
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