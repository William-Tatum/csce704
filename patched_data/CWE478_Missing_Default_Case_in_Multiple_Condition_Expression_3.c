#include <stdio.h>

void check_value(int value) {
    switch (value) {
        case 1:
            printf("Value is one.\n");
            break;
        case 2:
            printf("Value is two.\n");
            break;
        case 3:
            printf("Value is three.\n");
            break;
        default:
            fprintf(stderr, "Error: Value is not recognized. Default case is handling it.\n");
            break;
    }
}

int main() {
    check_value(1);
    check_value(4);
    return 0;
}