#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    
    if (a = b) {
        printf("This was meant to compare a and b, but does an assignment instead.\n");
    } else {
        printf("The values are different.\n");
    }
    
    return 0;
}