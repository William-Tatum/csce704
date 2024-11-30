#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = (char *)malloc(10 * sizeof(char));
    if (ptr == NULL) {
        return 1;
    }

    free(ptr);

    // Incorrectly freeing the same memory again
    free(ptr);

    return 0;
}