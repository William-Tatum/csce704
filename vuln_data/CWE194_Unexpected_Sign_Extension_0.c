#include <stdio.h>

void process(int number) {
    unsigned int extended_number;
    extended_number = (unsigned int)number;
    printf("Processed number: %u\n", extended_number);
}

int main() {
    short num = -5;
    process(num);
    return 0;
}