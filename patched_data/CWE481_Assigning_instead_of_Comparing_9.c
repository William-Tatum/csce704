#include <stdio.h>

void checkValue(int value) {
    if (value == 5) {
        printf("Value is 5\n");
    } else {
        printf("Value is not 5\n");
    }
}

int main() {
    int num = 3;
    checkValue(num);
    return 0;
}