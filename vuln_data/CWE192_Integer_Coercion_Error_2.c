#include <stdio.h>

void vulnerability_example() {
    unsigned int largeValue = 40000;
    short smallValue;

    smallValue = largeValue;
    printf("Small value: %d\n", smallValue);
}

int main() {
    vulnerability_example();
    return 0;
}