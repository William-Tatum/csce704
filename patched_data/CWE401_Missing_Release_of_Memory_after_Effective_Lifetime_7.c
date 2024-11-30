#include <stdio.h>
#include <stdlib.h>

void processData(const char* data) {
    char* buffer = (char*)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    snprintf(buffer, 100, "%s", data);
    printf("Processed: %s\n", buffer);
    free(buffer);
}

int main() {
    processData("Sample Input");
    return 0;
}