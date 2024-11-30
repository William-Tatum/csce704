#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = (char *)malloc(10);
    if (ptr == NULL) {
        return 1;
    }
    free(ptr);
    ptr = NULL;
    return 0;
}