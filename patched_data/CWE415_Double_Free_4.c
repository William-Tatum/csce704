#include <stdlib.h>

int main() {
    char *ptr = (char *)malloc(10);
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
        // Assume some logic here
    }
    return 0;
}