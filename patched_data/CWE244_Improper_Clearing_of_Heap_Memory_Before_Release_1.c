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

    secure_clear(sensitive_data, strlen(sensitive_data));

    char *new_data = (char *)malloc(100 * sizeof(char));
    if (new_data == NULL) {
        perror("Failed to allocate memory");
        secure_clear(sensitive_data, 50);
        free(sensitive_data);
        return 1;
    }

    strcpy(new_data, "NewData");

    secure_clear(new_data, strlen(new_data));
    free(new_data);

    secure_clear(sensitive_data, 50);
    free(sensitive_data);

    return 0;
}