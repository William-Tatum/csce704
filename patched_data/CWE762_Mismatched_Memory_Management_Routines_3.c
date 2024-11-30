#include <stdlib.h>

int main() {
    int *data;

    data = (int*) malloc(10 * sizeof(int));
    if (data == NULL) {
        return 1;
    }

    free(data);

    return 0;
}