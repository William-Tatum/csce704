#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    if (a = b) {
        printf("Inside if statement\n");
    } else {
        printf("Inside else statement\n");
    }

    printf("a: %d, b: %d\n", a, b);

    return 0;
}