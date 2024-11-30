#include <stdio.h>
#include <limits.h>

int main() {
    int data;
    data = INT_MIN + 10;
    
    if (data > INT_MIN) {
        data = data - 20;
        printf("Result: %d\n", data);
    } else {
        printf("Potential underflow detected\n");
    }
    
    return 0;
}