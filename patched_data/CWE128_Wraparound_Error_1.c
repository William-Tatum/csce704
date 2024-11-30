#include <stdio.h>

int main() {
    unsigned char uChar = 255;
    printf("Before increment: %u\n", uChar);
    if (uChar < 255) {
        uChar++;
    }
    printf("After increment: %u\n", uChar);
    return 0;
}