#include <stdio.h>
#include <limits.h>

void risky_function(unsigned int length) {
    char buffer[10];

    if (length < sizeof(buffer)) {
        buffer[length] = 'A';
        printf("Buffer index %u set successfully.\n", length);
    } else {
        printf("Invalid buffer index: %u\n", length);
    }
}

int main() {
    unsigned int large_value = UINT_MAX;
    risky_function(large_value);
    return 0;
}