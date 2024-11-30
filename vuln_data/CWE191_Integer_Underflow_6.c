#include <stdio.h>
#include <limits.h>

void subtract_and_check_underflow(int a, int b) {
    if (a < 0 && b > 0 && a - b > a) {
        printf("Integer underflow detected!\n");
    } else if (a > 0 && b < 0 && a - b < a) {
        printf("Integer overflow detected!\n");
    } else {
        int result = a - b;
        printf("Result of subtraction: %d\n", result);
    }
}

int main() {
    int x = INT_MIN;
    int y = 1;
    subtract_and_check_underflow(x, y);
    return 0;
}