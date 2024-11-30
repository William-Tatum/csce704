#include <stdlib.h>
#include <stdio.h>

int main() {
    char *ptr = malloc(10);
    if (ptr == NULL) {
        return 1; // handle allocation failure
    }

    free(ptr);

    // Unintentional second call to free with the same pointer
    free(ptr);

    return 0;
}