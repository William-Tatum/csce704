#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_realloc(void **ptr, size_t old_size, size_t new_size) {
    if (new_size == 0) {
        if (*ptr) {
            memset(*ptr, 0, old_size);
            free(*ptr);
            *ptr = NULL;
        }
        return;
    }

    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return;
    }

    if (*ptr) {
        memcpy(new_ptr, *ptr, old_size < new_size ? old_size : new_size);
        memset(*ptr, 0, old_size);
        free(*ptr);
    }
    *ptr = new_ptr;
}

int main() {
    char *sensitive_data = malloc(10);
    if (!sensitive_data) {
        return 1;
    }
    strncpy(sensitive_data, "password", 10);
    secure_realloc((void**)&sensitive_data, 10, 20);
    if (sensitive_data) {
        free(sensitive_data);
    }
    return 0;
}