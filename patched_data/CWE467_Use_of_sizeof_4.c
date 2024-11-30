#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safeFunction() {
    char *buffer = malloc(50);
    if (buffer == NULL) {
        return;
    }
    printf("Size of allocated memory: %zu\n", 50);
    strncpy(buffer, "This is a test", 49);
    buffer[49] = '\0';
    printf("%s\n", buffer);
    free(buffer);
}

int main() {
    safeFunction();
    return 0;
}