#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void untrustedFunction(char *data, size_t size) {
    strncpy(data, "Compromised", size - 1);
    data[size - 1] = '\0'; // Ensure null termination
}

int main() {
    char *sensitiveData = malloc(100);
    if (!sensitiveData) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(sensitiveData, "Original Data", 99);
    sensitiveData[99] = '\0'; // Ensure null termination

    char *clonedData = malloc(strlen(sensitiveData) + 1);
    if (!clonedData) {
        fprintf(stderr, "Memory allocation failed\n");
        free(sensitiveData);
        exit(1);
    }
    strncpy(clonedData, sensitiveData, strlen(sensitiveData) + 1);

    untrustedFunction(clonedData, strlen(sensitiveData) + 1);

    printf("Sensitive Data: %s\n", sensitiveData);
    printf("Cloned Data: %s\n", clonedData);

    free(sensitiveData);
    free(clonedData);

    return 0;
}