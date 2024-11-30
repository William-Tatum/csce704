#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    if (!ptr) {
        return 1;
    }

    free(ptr);

    return 0;
}