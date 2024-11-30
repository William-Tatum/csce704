#include <stdio.h>
#include <stdlib.h>

char* getStringAfterIndex(char* str, int index, int bufferSize) {
    if (index < 0 || index >= bufferSize) {
        return NULL;
    }
    return str + index;
}

int main() {
    const int bufferSize = 10;
    char* buffer = (char*)malloc((bufferSize + 1) * sizeof(char));

    if (buffer == NULL) {
        return 1;
    }

    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 'A' + i;
    }
    buffer[bufferSize] = '\0';

    int index = 5;
    char* result = getStringAfterIndex(buffer, index, bufferSize);

    if (result != NULL) {
        printf("Result: %s\n", result);
    } else {
        printf("Invalid index\n");
    }

    free(buffer);
    return 0;
}