#include <stdio.h>
#include <limits.h>

int main() {
    int x = INT_MIN;
    int y = 1;
    if (x <= INT_MIN + y) {
        printf("Integer underflow detected. Operation aborted.\n");
    } else {
        int result = x - y;
        printf("Result: %d\n", result);
    }
    return 0;
}