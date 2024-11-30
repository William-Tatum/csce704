#include <stdio.h>

int main() {
    double doubleValue = 1234.5678;
    int intValue;

    intValue = (int)doubleValue;

    printf("Incorrect conversion resulted in intValue: %d\n", intValue);

    return 0;
}