#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *intPtr = malloc(sizeof(int));
    if (intPtr == NULL) {
        return 1;
    }
    
    *intPtr = 42;
    
    char *charPtr = (char *)intPtr;
    
    printf("Interpreted value as char: %c\n", *charPtr);
    
    free(intPtr);
    return 0;
}