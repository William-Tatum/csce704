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
    
    void *temp = realloc(password, 32 * sizeof(char));
    if (!temp) {
        safe_free(password, 16);
        perror("Failed to reallocate memory");
        return 1;
    }
    password = (char *)temp;

    safe_free(password, 32);
    return 0;
}