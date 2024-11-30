#include <stdio.h>

int main() {
    short data;
    data = -1;

    unsigned short unsignedData = (unsigned short)data;
    int extendedData = (int)unsignedData;

    printf("Original data: %d\n", data);
    printf("Extended data: %d\n", extendedData);

    return 0;
}