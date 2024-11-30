#include <stdlib.h>

int main() {
    int *data = (int *) malloc(100 * sizeof(int));
    if (data == NULL) {
        return 1;
    }

    free(data);
    return 0;
}