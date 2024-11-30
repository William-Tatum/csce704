#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(const char *input, size_t length) {
    char buffer[50];
    if (length >= sizeof(buffer)) {
        printf("Error: Length parameter exceeds buffer size.\n");
        return;
    }
    memcpy(buffer, input, length);
    buffer[length] = '\0';
    printf("Processed data: %s\n", buffer);
}

int main() {
    char data[100];
    printf("Enter data: ");
    if (fgets(data, sizeof(data), stdin) != NULL) {
        size_t inputLength = strnlen(data, sizeof(data));
        if (inputLength > 0 && data[inputLength - 1] == '\n') {
            data[inputLength - 1] = '\0';
            inputLength--;
        }
        processData(data, inputLength);
    }
    return 0;
}