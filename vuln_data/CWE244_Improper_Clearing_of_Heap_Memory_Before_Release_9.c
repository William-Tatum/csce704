#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *sensitiveData = (char *)malloc(20 * sizeof(char));
    if (sensitiveData == NULL) {
        perror("Allocation failed");
        return 1;
    }

    strcpy(sensitiveData, "SensitivePassword");

    // Securely clearing sensitive data before reallocating
    volatile char *p = sensitiveData;
    while (*p) {
        *p++ = 0;
    }

    char *newBuffer = (char *)realloc(sensitiveData, 40 * sizeof(char));
    if (newBuffer == NULL) {
        perror("Reallocation failed");
        free(sensitiveData);
        return 1;
    }

    strcpy(newBuffer, "NewDataAddedHere");

    free(newBuffer);
    return 0;
}