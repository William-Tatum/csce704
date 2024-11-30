#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(const char *input) {
    char *data = (char *)malloc(strlen(input) + 1);
    if (data == NULL) {
        return;
    }
    strncpy(data, input, strlen(input) + 1);
    printf("Processing: %s\n", data);
    free(data);
}

int main() {
    processData("Example Data");
    return 0;
}