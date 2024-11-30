#include <stdio.h>
#include <limits.h>

void subtract_and_check_underflow(int a, int b) {
    if ((b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX + b)) {
        printf("Integer underflow or overflow detected!\n");
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