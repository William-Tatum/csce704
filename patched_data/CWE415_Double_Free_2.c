#include <stdlib.h>
#include <stdio.h>

int main() {
    char *ptr = (char *)malloc(100);
    if (ptr == NULL) {
        return 1;
    }

    free(ptr);
    ptr = NULL;

    return 0;
}