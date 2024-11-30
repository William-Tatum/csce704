#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int u = UINT_MAX;
    int s;
    if (u > INT_MAX) {
        s = INT_MAX;
    } else {
        s = (int)u;
    }
    printf("Unsigned: %u, Signed: %d\n", u, s);
    
    short small = 32767;
    int extended;
    if (small == SHRT_MAX) {
        extended = INT_MAX; // Prevent overflow
    } else {
        extended = (int)small + 1;
    }
    printf("Extended: %d\n", extended);
    
    int large = INT_MAX;
    short truncated;
    if (large > SHRT_MAX || large < SHRT_MIN) {
        truncated = (large > 0) ? SHRT_MAX : SHRT_MIN;
    } else {
        truncated = (short)large;
    }
    printf("Large: %d, Truncated: %d\n", large, truncated);
    
    return 0;
}