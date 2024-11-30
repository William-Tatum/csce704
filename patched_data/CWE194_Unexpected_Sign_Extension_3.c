#include <stdio.h>

void processInput(short data) {
    unsigned int extendedData = 0;
    extendedData = (unsigned int)(unsigned short)data;
    printf("Processed value: %u\n", extendedData);
}

int main() {
    short value = -10;
    processInput(value);
    return 0;
}