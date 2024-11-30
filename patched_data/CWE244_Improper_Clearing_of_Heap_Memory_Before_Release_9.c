#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_zero_memory(volatile void *ptr, size_t len) {
    volatile char *p = (volatile char *)ptr;
    while (len--) {
        *p++ = 0;
    }
}

int main() {
    char *sensitiveData = (char *)malloc(20 * sizeof(char));
    if (sensitiveData == NULL) {
        perror("Allocation failed");
        return 1;
    }

    strncpy(sensitiveData, "SensitivePassword", 19);
    sensitiveData[19] = '\0';

    char *newBuffer = (char *)malloc(40 * sizeof(char));
    if (newBuffer == NULL) {
        perror("Allocation for new buffer failed");
        secure_zero_memory(sensitiveData, 20);
        free(sensitiveData);
        return 1;
    }

    secure_zero_memory(sensitiveData, 20);
    free(sensitiveData);

    strncpy(newBuffer, "NewDataAddedHere", 39);
    newBuffer[39] = '\0';

    free(newBuffer);
    return 0;
}