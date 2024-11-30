#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_memory(char *ptr, size_t len) {
    if (ptr != NULL) {
        memset(ptr, 0, len);
        free(ptr);
    }
}

int main() {
    char *password = (char *)malloc(25 * sizeof(char));
    if (password == NULL) {
        return 1;
    }
    
    strcpy(password, "SensitivePasswordData");
    
    size_t old_size = 25;
    size_t new_size = 50;
    
    char *new_memory = (char *)malloc(new_size * sizeof(char));
    if (new_memory == NULL) {
        clear_memory(password, old_size);
        return 1;
    }

    memcpy(new_memory, password, old_size);
    clear_memory(password, old_size);

    // Use new_memory for sensitive operations

    clear_memory(new_memory, new_size);
    return 0;
}