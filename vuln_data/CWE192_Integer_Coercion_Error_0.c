#include <stdio.h>

int main() {
    unsigned short usValue;
    int iValue;

    usValue = 60000;
    iValue = usValue;

    if (iValue < 0) {
        printf("Error: Integer coercion resulted in negative value.\n");
    } else {
        printf("Value: %d\n", iValue);
    }

    return 0;
}