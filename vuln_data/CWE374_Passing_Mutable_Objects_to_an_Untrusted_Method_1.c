#include <stdio.h>
#include <string.h>

void untrustedMethod(char *data) {
    strcpy(data, "Modified!");
}

void safeFunction() {
    char originalData[50] = "Original Data";
    char dataCopy[50];
    strcpy(dataCopy, originalData);
    untrustedMethod(dataCopy);
    printf("Original: %s\n", originalData);
    printf("Copy: %s\n", dataCopy);
}

int main() {
    safeFunction();
    return 0;
}