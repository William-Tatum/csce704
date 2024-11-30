#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int a = 0;
    unsigned int b = 1;
    
    if (a < b) {
        printf("Underflow detected: Subtraction cannot be performed\n");
    } else {
        unsigned int result = a - b;
        printf("Result: %u\n", result);
    }

    int x = INT_MIN;
    int y = 1;

    if (x < 0 && y > 0 && x - y > x) {
        printf("Underflow detected: Subtraction cannot be performed\n");
    } else {
        int result2 = x - y;
        printf("Result: %d\n", result2);
    }

    return 0;
}