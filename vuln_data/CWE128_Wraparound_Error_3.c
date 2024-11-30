#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int max_value = UINT_MAX;
    max_value += 1;
    printf("Wrapped value: %u\n", max_value);
    return 0;
}