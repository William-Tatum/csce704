#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_realloc(void **ptr, size_t old_size, size_t new_size) {
    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return;
    }
    if (*ptr) {
        memcpy(new_ptr, *ptr, old_size < new_size ? old_size : new_size);
        memset(*ptr, 0, old_size); // Clear sensitive data from old memory
        free(*ptr);
    }
    *ptr = new_ptr;
}

int main() {
    char *sensitive_data = malloc(10);
    if (!sensitive_data) {
        return 1;
    }
    strcpy(sensitive_data, "password");
    secure_realloc((void**)&sensitive_data, 10, 20);
    free(sensitive_data);
    return 0;
}