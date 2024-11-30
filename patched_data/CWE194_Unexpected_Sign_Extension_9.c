#include <stdio.h>
#include <stdint.h>

int main() {
    short smallNum = -1;
    unsigned int largeNum = 0;

    largeNum = (unsigned int)(uint16_t)smallNum;

    printf("Corrected Value: %u\n", largeNum);
    return 0;
}