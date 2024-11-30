#include <stdio.h>
#include <stdlib.h>

int main() {
    int *data = (int *)malloc(10 * sizeof(int));
    if (data == NULL) {
        return 1;
    }
    
    // Correct operations on data

    free(data);

    return 0;
}