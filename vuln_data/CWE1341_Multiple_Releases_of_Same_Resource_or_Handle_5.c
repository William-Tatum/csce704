#include <stdio.h>
#include <stdlib.h>

void unsafe_double_free() {
    char *buffer = (char *)malloc(100);
    if (buffer == NULL) {
        return;
    }
   
    free(buffer);
    free(buffer); // Dangerous: Double free
}

int main() {
    unsafe_double_free();
    return 0;
}