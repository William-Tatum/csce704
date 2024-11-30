#include <stdio.h>

int main() {
    short data;
    data = -1;

    int extendedData = data;

    printf("Original data: %d\n", data);
    printf("Extended data: %d\n", extendedData);

    return 0;
}