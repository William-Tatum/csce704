#include <stdio.h>

int main() {
    unsigned short usValue;
    unsigned int iValue;

    usValue = 60000;
    iValue = usValue;

    printf("Value: %u\n", iValue);

    return 0;
}