#include <stdio.h>

void processInput(short data) {
    unsigned int extendedData = 0;
    if (data < 0) {
        printf("Unexpected sign extension can occur!\n");
    }
    extendedData = (unsigned int)data;
    printf("Processed value: %u\n", extendedData);
}

int main() {
    short value = -10;
    processInput(value);
    return 0;
}