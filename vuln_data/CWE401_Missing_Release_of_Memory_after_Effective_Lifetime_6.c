#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(const char *data) {
    char *buffer = (char *)malloc(256);
    if (buffer == NULL) {
        return;
    }
    strncpy(buffer, data, 255);
    buffer[255] = '\0';

    if (data == NULL || strlen(data) == 0) {
        free(buffer);
        return;
    }

    printf("Processed data: %s\n", buffer);
    free(buffer);
}

int main() {
    char *input1 = "Hello, World!";
    char *input2 = "";

    process_data(input1);
    process_data(input2);

    return 0;
}