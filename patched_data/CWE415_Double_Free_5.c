#include <stdlib.h>
#include <stdio.h>

int main() {
    char *ptr = (char *)malloc(10 * sizeof(char));
    if (ptr == NULL) {
        return 1;
    }
    
    free(ptr);
    ptr = NULL;

    return 0;
}