#include <stdlib.h>

int main() {
    char *ptr = (char *)malloc(10);
    if (ptr != NULL) {
        free(ptr);
        // Assume some logic here that incorrectly attempts to free the same memory again
        free(ptr); // Double Free Vulnerability
    }
    return 0;
}