#include <stdio.h>

int main() {
    int largeNumber = 300;
    char smallNumber;
    
    if (largeNumber < -128 || largeNumber > 127) {
        printf("Error: Number out of range for conversion to char.\n");
        return 1;
    }
    
    smallNumber = (char)largeNumber;

    printf("Original number: %d\n", largeNumber);
    printf("Converted number: %d\n", smallNumber);

    return 0;
}