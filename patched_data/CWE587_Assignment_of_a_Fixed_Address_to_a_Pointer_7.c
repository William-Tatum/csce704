#include <stdio.h>

int main() {
    int variable = 0;
    int *ptr = &variable;
    *ptr = 10;
    printf("%d\n", *ptr);
    return 0;
}