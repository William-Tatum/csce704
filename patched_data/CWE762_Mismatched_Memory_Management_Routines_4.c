#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    free(ptr);
    return 0;
}