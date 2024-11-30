#include <stdio.h>

int main() {
    int data[10];
    int *ptr = data;
    char *charPtr;
    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }
    charPtr = (char *)ptr;
    charPtr += 1;
    printf("Value: %d\n", *(int *)charPtr); 
    return 0;
}