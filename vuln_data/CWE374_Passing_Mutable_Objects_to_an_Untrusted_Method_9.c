#include <stdio.h>
#include <string.h>

void untrustedFunction(char *data) {
    // Untrusted code modifying the passed data
    strcpy(data, "modified by untrusted");
}

void secureFunction(char *data) {
    char dataClone[50];
    strncpy(dataClone, data, sizeof(dataClone) - 1);
    dataClone[sizeof(dataClone) - 1] = '\0'; // Ensure null-termination

    // Pass the clone to the untrusted function
    untrustedFunction(dataClone);

    // The original data remains unmodified
    printf("Original data: %s\n", data);
    printf("Modified clone: %s\n", dataClone);
}

int main() {
    char originalData[50] = "original data";
    secureFunction(originalData);
    return 0;
}