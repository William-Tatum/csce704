#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int) * 10);
    if (ptr == NULL) {
        return 1;
    }

    // Correct deallocation
    free(ptr);

    return 0;
}