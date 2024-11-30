#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_free(void *ptr, size_t size) {
    if (ptr) {
        volatile char *vptr = (volatile char *)ptr;
        while (size--) {
            *vptr++ = 0;
        }
        free(ptr);
    }
}

int main() {
    char *sensitive_data = (char *)malloc(100 * sizeof(char));
    if (!sensitive_data) {
        return 1;
    }

    strcpy(sensitive_data, "SuperSecretPassword123!");

    char *resized_buffer = (char *)realloc(sensitive_data, 200 * sizeof(char));
    if (!resized_buffer) {
        secure_free(sensitive_data, 100 * sizeof(char));
        return 1;
    }

    secure_free(resized_buffer, 200 * sizeof(char));

    return 0;
}