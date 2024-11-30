#include <stdio.h>

int main() {
    void *ptr;
    int num = 10;
    ptr = &num;
    char *charPtr;
    charPtr = (char *)ptr;
    printf("Value: %c\n", *charPtr);
    return 0;
}