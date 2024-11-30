#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to securely clear memory
void secure_clear(char *ptr, size_t size) {
    if (ptr == NULL) return;
    volatile char *p = ptr;
    while (size--) *p++ = 0;
}

int main() {
    char *sensitive_data = (char *)malloc(50 * sizeof(char));
    if (sensitive_data == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }
    strcpy(sensitive_data, "SensitiveInformation");

    // Securely clear the sensitive data before reallocating memory
    secure_clear(sensitive_data, strlen(sensitive_data));

    char *new_data = (char *)realloc(sensitive_data, 100 * sizeof(char));
    if (new_data == NULL) {
        perror("Failed to reallocate memory");
        free(sensitive_data);
        return 1;
    }

    strcpy(new_data, "NewData");

    // Use new_data ...

    secure_clear(new_data, 100);
    free(new_data);

    return 0;
}