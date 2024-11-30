#include <stdio.h>

void processNumber(short input) {
    unsigned int value = input;
    if (value < 1024) {
        printf("Value is within expected range: %u\n", value);
    } else {
        printf("Value exceeds expected range: %u\n", value);
    }
}

int main() {
    short num = -1;
    processNumber(num);
    return 0;
}