#include <stdio.h>

void process(int number) {
    if (number < 0) {
        printf("Error: Negative number not allowed\n");
        return;
    }
    unsigned int extended_number = (unsigned int)number;
    printf("Processed number: %u\n", extended_number);
}

int main() {
    short num = -5;
    process(num);
    return 0;
}