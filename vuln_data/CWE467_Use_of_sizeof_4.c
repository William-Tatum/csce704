#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unsafeFunction() {
    char *buffer = malloc(50);
    if (buffer == NULL) {
        return;
    }
    printf("Size of allocated memory: %lu\n", sizeof(buffer));
    strcpy(buffer, "This is a test");
    printf("%s\n", buffer);
    free(buffer);
}

int main() {
    unsafeFunction();
    return 0;
}