#include <stdio.h>
#include <limits.h>

int main() {
    unsigned char c = 255;
    if (c < UCHAR_MAX) {
        c += 1;
    }
    printf("Value after increment: %u\n", c);
    return 0;
}