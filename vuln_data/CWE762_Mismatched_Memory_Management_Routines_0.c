#include <stdlib.h>

int main() {
    int *data = (int *) malloc(100 * sizeof(int));
    if (data == NULL) {
        return 1;
    }

    // Incorrectly deallocating with delete instead of free
    // delete[] data;  // Incorrect usage in C, use comment to illustrate wrong practice

    free(data); // Correct deallocation
    return 0;
}