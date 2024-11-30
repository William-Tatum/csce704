#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = malloc(50);
    if (buffer == NULL) {
        return -1;
    }
    
    /* Improper use of sizeof */
    size_t bufferSize = sizeof(buffer);

    if (bufferSize > 0) {
        strcpy(buffer, "This is a test.");
    }
    
    printf("Buffer size according to sizeof: %zu\n", bufferSize);
    printf("Buffer contents: %s\n", buffer);

    free(buffer);
    return 0;
}