#include <stdio.h>

int main() {
    int x = 1;
    if (x > 0) {
        printf("X is positive\n");
        x = -1;
    }

    if (x > 0) {
        printf("X is still positive\n");
    } else {
        printf("X is not positive\n");
    }

    return 0;
}