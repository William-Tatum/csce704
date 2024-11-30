#include <stdio.h>
#include <string.h>

void untrustedFunction(char *data) {
    strcpy(data, "Data Modified by Untrusted Function");
}

int main() {
    char originalData[] = "Important Data";
    char clonedData[50];

    strcpy(clonedData, originalData);

    untrustedFunction(clonedData);

    printf("Original Data: %s\n", originalData);
    printf("Cloned Data after untrusted call: %s\n", clonedData);

    return 0;
}