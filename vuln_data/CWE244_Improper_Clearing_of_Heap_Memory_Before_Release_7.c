#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_free(void *ptr, size_t size) {
    volatile char *p = (volatile char *)ptr;
    while (size--) {
        *p++ = 0;
    }
    free(ptr);
}

int main() {
    char *buffer = (char *)malloc(16 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }

    strcpy(buffer, "SensitiveData");

    size_t old_size = 16 * sizeof(char);
    char *new_buffer = (char *)realloc(buffer, 32 * sizeof(char));
    if (new_buffer == NULL) {
        secure_free(buffer, old_size);
        return 1;
    }

    secure_free(buffer, old_size);
    buffer = new_buffer;

    strcat(buffer, "MoreData");

    secure_free(buffer, 32 * sizeof(char));
    return 0;
}