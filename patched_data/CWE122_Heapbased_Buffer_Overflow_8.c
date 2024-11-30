#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safeFunction(const char *input) {
    char *heapBuffer;
    size_t inputLength = strlen(input);
    heapBuffer = (char *)malloc((inputLength + 1) * sizeof(char));
    if (heapBuffer == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strncpy(heapBuffer, input, inputLength);
    heapBuffer[inputLength] = '\0';
    printf("Buffer Content: %s\n", heapBuffer);
    free(heapBuffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        safeFunction(argv[1]);
    } else {
        printf("Please provide an input string.\n");
    }
    return 0;
}