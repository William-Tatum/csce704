#include <string.h>
#include <stdlib.h>

void secure_memset(void *ptr, int value, size_t len) {
    volatile unsigned char *volatile_mem = (volatile unsigned char *)ptr;
    while (len--) {
        *volatile_mem++ = (unsigned char)value;
    }
}

int main() {
    char *sensitive_data = (char *)malloc(64);
    if (sensitive_data == NULL) return 1;
    strcpy(sensitive_data, "This is some sensitive data");
    
    // Use sensitive data for some operation here
    
    secure_memset(sensitive_data, 0, 64);
    free(sensitive_data);
    return 0;
}