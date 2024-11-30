#include <stdio.h>

void checkValue(int value) {
    switch (value) {
        case 1:
            printf("Value is 1\n");
            break;
        case 2:
            printf("Value is 2\n");
            break;
        case 3:
            printf("Value is 3\n");
            break;
        default:
            printf("Value is unrecognized\n");
            break;
    }
}

int main() {
    int testValues[] = {0, 1, 2, 3, 4};
    for(int i = 0; i < sizeof(testValues)/sizeof(testValues[0]); i++) {
        checkValue(testValues[i]);
    }
    return 0;
}