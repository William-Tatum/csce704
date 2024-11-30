#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    buffer = malloc(10);

    if(buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    strcpy(buffer, "This string is too long for the buffer");
    printf("Buffer: %s\n", buffer);

    free(buffer);
    return 0;
}