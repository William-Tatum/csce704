#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int counter = UINT_MAX;
    printf("Counter before increment: %u\n", counter);
    counter++;
    printf("Counter after increment: %u\n", counter);
    return 0;
}