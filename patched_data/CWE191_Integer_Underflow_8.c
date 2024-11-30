#include <stdio.h>
#include <limits.h>

void check_underflow(int x, int y) {
    if (y > 0 && x < INT_MIN + y) {
        printf("An underflow would occur.\n");
    } else {
        int result = x - y;
        printf("Result: %d\n", result);
    }
}

int main() {
    int x = INT_MIN;
    int y = 1;
    check_underflow(x, y);
    return 0;
}