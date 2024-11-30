#include <stdio.h>
#include <limits.h>

int main() {
    int num1 = INT_MIN;
    int num2 = 1;
    int result;

    if (num1 > INT_MIN + num2) {
        result = num1 - num2;
        printf("Result: %d\n", result);
    } else {
        printf("Integer underflow prevented.\n");
    }

    return 0;
}