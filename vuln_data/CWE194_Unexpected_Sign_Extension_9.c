#include <stdio.h>
#include <stdint.h>

int main() {
    short smallNum = -1;
    unsigned int largeNum = 0;

    largeNum = smallNum;

    printf("Unexpected Value Due to Sign Extension: %u\n", largeNum);
    return 0;
}