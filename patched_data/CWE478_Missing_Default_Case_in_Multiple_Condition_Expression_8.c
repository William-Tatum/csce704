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
            printf("Value is unknown: %d\n", value);
            break;
    }
}

int main() {
    int testValue;
    if (scanf("%d", &testValue) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    checkValue(testValue);
    return 0;
}