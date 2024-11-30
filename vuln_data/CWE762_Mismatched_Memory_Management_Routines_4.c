#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    // Mismatched deallocation routine
    delete ptr; // Incorrect usage, should use free() instead of delete
    return 0;
}