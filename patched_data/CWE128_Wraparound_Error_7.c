#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int max_value = UINT_MAX;
    printf("Max unsigned int: %u\n", max_value);

    unsigned int wrap_around = 0;
    printf("Wrap around value: %u\n", wrap_around);

    return 0;
}