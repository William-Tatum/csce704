#include <stdlib.h>

int main() {
    char *buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }

    // Memory management mismatch: allocated with malloc, incorrectly deallocated with delete
    delete buffer;

    return 0;
}