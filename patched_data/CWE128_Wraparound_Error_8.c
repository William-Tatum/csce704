#include <stdio.h>
#include <limits.h>

void wrapAroundError() {
    unsigned int x = UINT_MAX;
    printf("Value before increment: %u\n", x);
    
    if (x < UINT_MAX) {
        x++;
    } else {
        printf("Increment would cause wrap around.\n");
    }
    
    printf("Value after increment: %u\n", x);
}

int main() {
    wrapAroundError();
    return 0;
}