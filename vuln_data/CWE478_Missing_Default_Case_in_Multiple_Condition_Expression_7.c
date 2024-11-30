#include <stdio.h>

void processValue(int value) {
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
            printf("Value is unknown\n");
            break;
    }
}

int main() {
    processValue(2);  // Prints "Value is 2"
    processValue(5);  // Prints "Value is unknown"
    return 0;
}