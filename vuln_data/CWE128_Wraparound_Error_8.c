#include <stdio.h>
#include <limits.h>

void wrapAroundError() {
    unsigned int x = UINT_MAX;
    printf("Value before increment: %u\n", x);
    x++;
    printf("Value after increment: %u\n", x);
}

int main() {
    wrapAroundError();
    return 0;
}