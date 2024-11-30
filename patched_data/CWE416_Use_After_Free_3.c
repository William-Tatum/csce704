#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    if (ptr == NULL) {
        return -1;
    }
    
    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
    }
    
    free(ptr);
    ptr = NULL;
    
    int *newPtr = (int *)malloc(sizeof(int) * 10);
    if (newPtr == NULL) {
        return -1;
    }
    
    for (int i = 0; i < 10; i++) {
        newPtr[i] = i + 10;
    }
    
    printf("%d\n", newPtr[1]);
    
    free(newPtr);
    newPtr = NULL;

    return 0;
}