#include <stdio.h>
#include <string.h>

void untrustedMethod(char *data, size_t maxSize) {
    strncpy(data, "Modified!", maxSize - 1);
    data[maxSize - 1] = '\0';
}

void safeFunction() {
    char originalData[50] = "Original Data";
    char dataCopy[50];
    strncpy(dataCopy, originalData, sizeof(dataCopy) - 1);
    dataCopy[sizeof(dataCopy) - 1] = '\0';
    untrustedMethod(dataCopy, sizeof(dataCopy));
    printf("Original: %s\n", originalData);
    printf("Copy: %s\n", dataCopy);
}

int main() {
    safeFunction();
    return 0;
}