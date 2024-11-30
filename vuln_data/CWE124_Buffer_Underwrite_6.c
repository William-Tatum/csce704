#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buffer_underwrite() {
    char *buffer = (char *)malloc(10);
    if (buffer == NULL) exit(1);

    char *ptr = buffer;

    // Incorrectly decrement pointer to before the start of the buffer
    ptr -= 1;

    // Attempt to write to memory location before valid buffer
    memset(ptr, 'A', 1);

    free(buffer);
}

int main() {
    buffer_underwrite();
    return 0;
}