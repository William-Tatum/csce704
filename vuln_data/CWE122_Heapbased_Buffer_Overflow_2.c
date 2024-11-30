#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = (char *)malloc(10 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }
    strcpy(buffer, "This is a string that is way too long for the buffer");
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}