#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
    double doubleValue = 1234.5678;
    int intValue;

    if (doubleValue > INT_MAX || doubleValue < INT_MIN) {
        fprintf(stderr, "Error: double value out of int range\n");
        return 1;
    }

    intValue = (int)round(doubleValue);

    printf("Correct conversion resulted in intValue: %d\n", intValue);

    return 0;
}