#include <stdio.h>
#include <string.h>

void clear_sensitive_data(volatile char *buffer, size_t size) {
    if (buffer == NULL || size == 0) {
        return;
    }
    volatile char *ptr = buffer;
    while (size--) {
        *ptr++ = 0;
    }
}

int main() {
    char sensitive_data[100];
    strncpy(sensitive_data, "SecretPassword123", sizeof(sensitive_data) - 1);
    sensitive_data[sizeof(sensitive_data) - 1] = '\0';

    // Use sensitive_data for something

    clear_sensitive_data(sensitive_data, sizeof(sensitive_data));

    return 0;
}