#include <stdio.h>
#include <stdlib.h>

void safe_memory_release() {
    char *buffer = (char *)malloc(100);
    if (buffer == NULL) {
        return;
    }
   
    free(buffer);
    buffer = NULL;
}

int main() {
    safe_memory_release();
    return 0;
}