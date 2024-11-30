#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copyString(const char *source) {
    size_t length = strlen(source) + 1;
    char *buffer = (char *)malloc(length);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(buffer, source, length);
    printf("Copied string: %s\n", buffer);
    free(buffer);
}

int main() {
    const char *original = "This is a very long string";
    copyString(original);
    return 0;
}