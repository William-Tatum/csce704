#include <stdio.h>

int main() {
    int num = 65;
    void *ptr = &num;
    char *charPtr = (char *)ptr;
    printf("Char representation: %c\n", *charPtr);
    return 0;
}