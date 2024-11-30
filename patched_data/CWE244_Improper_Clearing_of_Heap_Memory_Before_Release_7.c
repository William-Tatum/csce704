#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_free(void *ptr, size_t size) {
    if (ptr == NULL) return;
    volatile char *p = (volatile char *)ptr;
    while (size--) {
        *p++ = 0;
    }
    free(ptr);
}

int main() {
    size_t old_size = 16 * sizeof(char);
    char *buffer = (char *)malloc(old_size);
    if (buffer == NULL) {
        return 1;
    }

    strncpy(buffer, "SensitiveData", old_size - 1);
    buffer[old_size - 1] = '\0';

    size_t new_size = 32 * sizeof(char);
    char *new_buffer = (char *)realloc(buffer, new_size);
    if (new_buffer == NULL) {
        secure_free(buffer, old_size);
        return 1;
    }

    secure_free(buffer, old_size);
    buffer = new_buffer;

    strncat(buffer, "MoreData", new_size - strlen(buffer) - 1);

    secure_free(buffer, new_size);
    return 0;
}