#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int) * 10);
    if (ptr == NULL) {
        return 1;
    }

    // Incorrect deallocation
    delete ptr; // Mismatched memory management routine

    return 0;
}