#include <stdio.h>

int main() {
    int largeNumber = 300;
    char smallNumber;
    
    // Implicit casting of int to char, which may cause truncation
    smallNumber = largeNumber;
    
    printf("Original number: %d\n", largeNumber);
    printf("Truncated number: %d\n", smallNumber);

    return 0;
}