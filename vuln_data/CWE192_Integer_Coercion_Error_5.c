#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int u = UINT_MAX;
    int s = (int)u;
    printf("Unsigned: %u, Signed: %d\n", u, s);
    
    short small = 32767;
    int extended = (int)small + 1;
    printf("Extended: %d\n", extended);
    
    int large = INT_MAX;
    short truncated = (short)large;
    printf("Large: %d, Truncated: %d\n", large, truncated);
    
    return 0;
}