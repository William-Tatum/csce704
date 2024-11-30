#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int counter = UINT_MAX;
    printf("Counter before increment: %u\n", counter);
    if (counter < UINT_MAX) {
        counter++;
    } else {
        printf("Counter is at its maximum value and cannot be incremented.\n");
    }
    printf("Counter after increment handling: %u\n", counter);
    return 0;
}