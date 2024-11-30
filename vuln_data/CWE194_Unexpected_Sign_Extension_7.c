#include <stdio.h>

int main() {
    short smallValue = -1;
    unsigned int largeValue;
    
    largeValue = smallValue;
    
    printf("largeValue: %u\n", largeValue);
    
    return 0;
}