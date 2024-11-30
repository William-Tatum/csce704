#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size = 10;
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        return 1;
    }
    
    if (size <= 8) {
        free(buffer);
        return 1;
    }

    strcpy(buffer, "ABCDEFGH");

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}