#include <stdlib.h>

int main() {
    int *array = malloc(10 * sizeof(int));
    if (array == NULL) {
        return -1;
    }

    // Incorrectly deallocating memory with delete instead of free
    delete array; // Mismatched memory management routines

    return 0;
}