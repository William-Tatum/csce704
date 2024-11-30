#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(const char *data) {
    if (data == NULL || strlen(data) == 0) {
        return;
    }

    char *buffer = (char *)malloc(256);
    if (buffer == NULL) {
        return;
    }

    strncpy(buffer, data, 255);
    buffer[255] = '\0';

    printf("Processed data: %s\n", buffer);
    free(buffer);
}

int main() {
    const char *input1 = "Hello, World!";
    const char *input2 = "";

    process_data(input1);
    process_data(input2);

    return 0;
}