#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size = 10;
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        return 1;
    }

    char largeInput[] = "This input is definitely too large for the buffer";
    strcpy(buffer, largeInput);

    printf("Buffer content: %s\n", buffer);

    free(buffer);
    return 0;
}