#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(char *input, size_t length) {
    char buffer[50];
    if (length > 50) {
        printf("Error: Length parameter exceeds buffer size.\n");
        return;
    }
    strncpy(buffer, input, length);
    buffer[length] = '\0';
    printf("Processed data: %s\n", buffer);
}

int main() {
    char data[100];
    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);

    size_t inputLength = strlen(data);
    if (data[inputLength - 1] == '\n') {
        data[inputLength - 1] = '\0';
        inputLength--;
    }

    processData(data, inputLength);

    return 0;
}