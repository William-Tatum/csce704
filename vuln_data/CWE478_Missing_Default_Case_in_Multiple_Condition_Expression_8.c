#include <stdio.h>

void checkValue(int value) {
    switch (value) {
        case 0:
            printf("Value is zero\n");
            break;
        case 1:
            printf("Value is one\n");
            break;
        case 2:
            printf("Value is two\n");
            break;
        default:
            printf("Value is unknown\n");
            break;
    }
}

int main() {
    int testValue = 3;
    checkValue(testValue);
    return 0;
}