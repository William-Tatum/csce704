#include <stdio.h>
#include <string.h>

void clear_sensitive_data(volatile char *buffer, size_t size) {
    volatile char *ptr = buffer;
    while (size--) {
        *ptr++ = 0;
    }
}

int main() {
    char sensitive_data[100];
    strcpy(sensitive_data, "SecretPassword123");

    // Use sensitive_data for something

    clear_sensitive_data(sensitive_data, sizeof(sensitive_data));

    return 0;
}