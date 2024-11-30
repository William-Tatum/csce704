#include <stdio.h>
#include <limits.h>

int main() {
    int largeNumber = 300;
    char smallNumber;

    if (largeNumber > CHAR_MAX || largeNumber < CHAR_MIN) {
        printf("Error: Numeric truncation may occur.\n");
    } else {
        smallNumber = (char)largeNumber;
        printf("Converted number: %d\n", smallNumber);
    }

    return 0;
}