#include <stdio.h>

int main() {
    int condition = 1;
    int x = 0;
    
    if (condition)
        x = 10;
        printf("Block without braces\n");
    
    printf("x: %d\n", x);
    
    return 0;
}