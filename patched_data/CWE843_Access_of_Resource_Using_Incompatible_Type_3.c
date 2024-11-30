#include <stdio.h>

int main() {
    int num = 65;
    int *ptr = &num;
    printf("Integer representation: %d\n", *ptr);
    return 0;
}