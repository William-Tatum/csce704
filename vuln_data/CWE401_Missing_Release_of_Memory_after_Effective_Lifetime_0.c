#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(const char *input) {
    char *data = (char *)malloc(strlen(input) + 1);
    if (data == NULL) {
        return;
    }
    strcpy(data, input);
    // Simulate processing by printing
    printf("Processing: %s\n", data);
    // Memory not released, causing a memory leak
    // free(data);
}

int main() {
    processData("Example Data");
    return 0;
}