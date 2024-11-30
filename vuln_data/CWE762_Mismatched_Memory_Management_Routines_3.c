#include <stdlib.h>

int main() {
    int *data;

    data = (int*) malloc(10 * sizeof(int));
    if (data == NULL) {
        return 1;
    }

    delete data; // Incorrect deallocation, should use free(data);

    return 0;
}