#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_memory(volatile char *buffer, size_t size) {
    if (buffer != NULL) {
        volatile char *ptr = buffer;
        while (size--) {
            *ptr++ = 0;
        }
    }
}

int main() {
    char *sensitive_data = (char *)malloc(100 * sizeof(char));
    if (sensitive_data == NULL) {
        return 1;
    }

    strncpy(sensitive_data, "ThisIsASensitivePassword", 99);
    sensitive_data[99] = '\0';

    clear_memory(sensitive_data, strlen(sensitive_data));
    free(sensitive_data);
    return 0;
}