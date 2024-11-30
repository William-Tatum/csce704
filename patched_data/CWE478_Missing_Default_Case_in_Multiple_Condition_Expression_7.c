#include <stdio.h>

void processValue(int value) {
    if (value < 1 || value > 3) {
        printf("Value is unknown\n");
        return;
    }

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
    }
}

int main() {
    processValue(2);
    processValue(5);
    return 0;
}