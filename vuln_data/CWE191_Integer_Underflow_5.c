#include <stdio.h>
#include <limits.h>

int main() {
    int a = INT_MIN;
    int b = 1;
    int result;

    if (a - b > a) {
        printf("Integer underflow detected\n");
    } else {
        result = a - b;
        printf("Result: %d\n", result);
    }

    return 0;
}