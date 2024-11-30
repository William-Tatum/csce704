#include <stdlib.h>

int main() {
    int *array = malloc(10 * sizeof(int));
    if (array == NULL) {
        return -1;
    }

    free(array);

    return 0;
}