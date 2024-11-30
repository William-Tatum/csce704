#include <stdio.h>
#include <limits.h>

int main() {
    int a = INT_MIN;
    int b = 1;
    int result;

    if (b > 0 && a < INT_MIN + b) {
        printf("Integer underflow detected\n");
    } else {
        result = a - b;
        printf("Result: %d\n", result);
    }

    return 0;
}