#include <stdio.h>
#include <limits.h>

void processInput(short data) {
    unsigned long result;
    if (data < 0) {
        printf("Error: Negative input cannot be processed.\n");
        return;
    }
    result = data;
    printf("Result: %lu\n", result);
}

int main() {
    short data = -1;
    if (data < 0) {
        printf("Error: Invalid input value.\n");
        return 1;
    }
    processInput(data);
    return 0;
}