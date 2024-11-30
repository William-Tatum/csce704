#include <stdio.h>
#include <math.h>

void process(int value) {
    printf("Processed value: %d\n", value);
}

int main() {
    double input = 42.56;
    if (input > (double)INT_MAX || input < (double)INT_MIN) {
        fprintf(stderr, "Error: input value is out of range for an int.\n");
        return 1;
    }
    int roundedInput = (int)round(input);
    process(roundedInput);
    return 0;
}