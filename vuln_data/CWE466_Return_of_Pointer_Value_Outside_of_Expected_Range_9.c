#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getStringWithinRange(char *input, size_t size) {
    if (input == NULL || size == 0) {
        return NULL;
    }
    char *buffer = (char *)malloc(size + 1);
    if (buffer == NULL) {
        return NULL;
    }
    strncpy(buffer, input, size);
    buffer[size] = '\0';
    if (strlen(buffer) < size) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

int main() {
    char *input = "HelloWorld";
    char *result = getStringWithinRange(input, 5);
    if (result != NULL) {
        printf("Result: %s\n", result);
        free(result);
    } else {
        printf("Pointer outside of expected range or other error.\n");
    }
    return 0;
}