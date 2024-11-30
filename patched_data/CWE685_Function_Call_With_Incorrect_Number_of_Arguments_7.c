#include <stdio.h>

int add(int, int);

int main() {
    int a = 5, b = 10;
    int result;

    result = add(a, b);
    
    printf("Result: %d\n", result);
    return 0;
}

int add(int x, int y) {
    return x + y;
}