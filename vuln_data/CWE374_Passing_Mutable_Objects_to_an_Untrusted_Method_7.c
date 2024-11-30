#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void untrustedFunction(char *data) {
    strcpy(data, "Compromised");
}

int main() {
    char *sensitiveData = malloc(100);
    strcpy(sensitiveData, "Original Data");

    char *clonedData = malloc(strlen(sensitiveData) + 1);
    strcpy(clonedData, sensitiveData);

    untrustedFunction(clonedData);

    printf("Sensitive Data: %s\n", sensitiveData);
    printf("Cloned Data: %s\n", clonedData);

    free(sensitiveData);
    free(clonedData);

    return 0;
}