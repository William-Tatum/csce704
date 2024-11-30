#include <stdio.h>

void process(int value) {
    printf("Processing value: %d\n", value);
}

int main() {
    int correctValue = 42;
    int incorrectValue = 65; // ASCII value of 'A' assigned to an integer

    process(incorrectValue);

    return 0;
}