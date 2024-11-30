#include <stdio.h>

void process(int value) {
    printf("Processing value: %d\n", value);
}

int main() {
    int correctValue = 42;
    int incorrectValue = 'A'; // Should be an integer but a char is used

    process(incorrectValue);

    return 0;
}