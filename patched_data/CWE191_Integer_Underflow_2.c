#include <stdio.h>
#include <limits.h>

void handleUnderflow(int a, int b) {
    if ((b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX + b)) {
        printf("Integer underflow detected!\n");
        return;
    }
    int result = a - b;
    printf("Result is: %d\n", result);
}

int main() {
    int a = INT_MIN;
    int b = 1;
    handleUnderflow(a, b);
    return 0;
}