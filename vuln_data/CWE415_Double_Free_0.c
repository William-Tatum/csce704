#include <stdlib.h>
#include <stdio.h>

int main() {
    char *data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) {
        return 1; // handle allocation failure
    }
    free(data);
    data = NULL; // mitigate double free by setting pointer to NULL
    // Prevent double free by checking if pointer is NULL
    if (data != NULL) {
        free(data);
    }
    return 0;
}