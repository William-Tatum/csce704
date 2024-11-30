#include <stdio.h>

void processInput(short data) {
    unsigned long result;
    result = data;
    printf("Result: %lu\n", result);
}

int main() {
    short data = -1;
    processInput(data);
    return 0;
}