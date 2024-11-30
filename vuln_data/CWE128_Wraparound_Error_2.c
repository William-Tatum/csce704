#include <stdio.h>

int main() {
    unsigned char c = 255;
    c += 1;
    printf("Value after wrap-around: %u\n", c);
    return 0;
}