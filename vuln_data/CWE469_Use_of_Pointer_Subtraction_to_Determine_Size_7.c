#include <stdio.h>
#include <string.h>

int main() {
    char array1[10];
    char array2[10];
    
    char *ptr1 = &array1[2];
    char *ptr2 = &array2[6];
    
    long diff = ptr2 - ptr1;
    
    printf("Difference: %ld\n", diff);
    
    return 0;
}