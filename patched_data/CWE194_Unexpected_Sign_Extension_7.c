#include <stdio.h>

int main() {
    short smallValue = -1;
    unsigned int largeValue;
    
    if (smallValue >= 0) {
        largeValue = smallValue;
    } else {
        largeValue = 0; // or handle error
    }
    
    printf("largeValue: %u\n", largeValue);
    
    return 0;
}