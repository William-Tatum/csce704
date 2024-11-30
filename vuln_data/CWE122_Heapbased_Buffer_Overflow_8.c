#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerableFunction(const char *input) {
    char *heapBuffer;
    heapBuffer = (char *)malloc(10 * sizeof(char));
    strcpy(heapBuffer, input);
    printf("Buffer Content: %s\n", heapBuffer);
    free(heapBuffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        vulnerableFunction(argv[1]);
    } else {
        printf("Please provide an input string.\n");
    }
    return 0;
}