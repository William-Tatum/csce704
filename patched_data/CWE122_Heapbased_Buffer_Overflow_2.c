#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = (char *)malloc(50 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }
    strncpy(buffer, "This is a string that is way too long for the buffer", 49);
    buffer[49] = '\0';
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}