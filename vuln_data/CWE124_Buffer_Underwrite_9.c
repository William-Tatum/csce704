#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size = 10;
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        return 1;
    }

    char *ptr = buffer;

    // CWE-124: Buffer Underwrite
    ptr -= 1; // Dangerous operation leading ptr to point before allocated buffer
    strcpy(ptr, "ABCDEFGH"); // This writes before the starting address of buffer

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}