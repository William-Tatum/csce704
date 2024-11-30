#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_free(void *ptr, size_t size) {
    if (ptr == NULL) return;
    volatile char *p = ptr;
    while (size--) *p++ = 0;
    free(ptr);
}

int main() {
    char *sensitive_data = (char *)malloc(128 * sizeof(char));
    if (!sensitive_data) return 1;
    
    strncpy(sensitive_data, "SensitivePassword123", 127);
    sensitive_data[127] = '\0';

    char *temp = (char *)malloc(256 * sizeof(char));
    if (!temp) {
        secure_free(sensitive_data, 128);
        return 1;
    }
    
    memcpy(temp, sensitive_data, 128);
    secure_free(sensitive_data, 128);

    printf("Data: %.127s\n", temp);

    secure_free(temp, 256);
    return 0;
}