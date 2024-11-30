#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void safe_free(void *ptr, size_t size) {
    if (ptr != NULL) {
        volatile char *volatile p = (volatile char *volatile)ptr;
        while (size--) {
            *p++ = 0;
        }
        free(ptr);
    }
}

int main() {
    char *password = (char *)malloc(16 * sizeof(char));
    if (!password) {
        perror("Failed to allocate memory");
        return 1;
    }

    strcpy(password, "SensitivePass");
    
    password = (char *)realloc(password, 32 * sizeof(char));
    if (!password) {
        perror("Failed to reallocate memory");
        return 1;
    }

    safe_free(password, 32);
    return 0;
}