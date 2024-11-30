#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer;

    buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }

    free(buffer);
    // Potentially unsafe double free
    free(buffer);

    return 0;
}