#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }
    
    if (malloc_usable_size(buffer) == 100) {
        printf("Correct result: malloc_usable_size(buffer) == 100\n");
    } else {
        printf("Unexpected result: malloc_usable_size(buffer) == %zu\n", malloc_usable_size(buffer));
    }

    strncpy(buffer, "Hello, World!", 99);
    buffer[99] = '\0';
    printf("%s\n", buffer);
    free(buffer);
    
    return 0;
}