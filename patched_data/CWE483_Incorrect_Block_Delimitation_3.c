#include <stdio.h>

int main() {
    int x = 5, y = 10;

    if (x < y) {
        printf("x is less than y\n");
        x = y + 1;
    }

    printf("x: %d, y: %d\n", x, y);
    return 0;
}