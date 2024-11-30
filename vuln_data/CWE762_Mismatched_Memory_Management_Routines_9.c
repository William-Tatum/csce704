#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    if (!ptr) {
        return 1;
    }
    
    // Incorrectly using 'delete' instead of 'free' to deallocate memory
    delete ptr;

    return 0;
}