#include <stdio.h>
#include <stdlib.h>

int main() {
    int *data = (int *)malloc(10 * sizeof(int));
    if (data == NULL) {
        return 1;
    }
    
    // Correct operations on data

    // Incorrect deallocation using 'delete' instead of 'free'
    delete data;

    return 0;
}