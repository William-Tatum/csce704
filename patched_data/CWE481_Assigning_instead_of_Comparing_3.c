#include <stdio.h>

void check_value(int a) {
    if (a == 10) {
        printf("The value of a is 10\n");
    } else {
        printf("The value of a is not 10\n");
    }
}

int main() {
    int x = 5;
    check_value(x);
    return 0;
}