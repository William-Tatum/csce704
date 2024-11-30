#include <stdio.h>
#include <string.h>

void untrustedFunction(char *data) {
    strncpy(data, "modified by untrusted", strlen("modified by untrusted"));
    data[strlen("modified by untrusted")] = '\0';
}

void secureFunction(char *data) {
    char dataClone[50] = {0};
    strncpy(dataClone, data, sizeof(dataClone) - 1);
    dataClone[sizeof(dataClone) - 1] = '\0';

    untrustedFunction(dataClone);

    printf("Original data: %s\n", data);
    printf("Modified clone: %s\n", dataClone);
}

int main() {
    char originalData[50] = "original data";
    secureFunction(originalData);
    return 0;
}