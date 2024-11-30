#include <stdio.h>
#include <limits.h>

void vulnerability_example() {
    unsigned int largeValue = 40000;
    short smallValue;

    if (largeValue > SHRT_MAX) {
        printf("Value exceeds range for a short type. Cannot assign.\n");
    } else {
        smallValue = (short)largeValue;
        printf("Small value: %d\n", smallValue);
    }
}

int main() {
    vulnerability_example();
    return 0;
}