#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_memory(char *buffer, size_t size) {
    if (buffer != NULL) {
        memset(buffer, 0, size);
    }
}

int main() {
    char *sensitive_data = (char *)malloc(100 * sizeof(char));
    if (sensitive_data == NULL) {
        return 1;
    }

    strcpy(sensitive_data, "ThisIsASensitivePassword");
    
    clear_memory(sensitive_data, strlen(sensitive_data));
    free(sensitive_data);
    return 0;
}