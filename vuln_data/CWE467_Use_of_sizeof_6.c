#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }
    
    if (sizeof(buffer) == 100) {
        printf("Unexpected result: sizeof(buffer) == 100\n");
    } else {
        printf("Unexpected result: sizeof(buffer) == %zu\n", sizeof(buffer));
    }

    strcpy(buffer, "Hello, World!");
    printf("%s\n", buffer);
    free(buffer);
    
    return 0;
}