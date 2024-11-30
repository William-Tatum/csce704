#include <stdio.h>

int main() {
    int x = 5;
    int y = 10;
    
    if (x < y)
        x = y;
        printf("x is less than y\n");

    printf("Value of x: %d\n", x);

    return 0;
}