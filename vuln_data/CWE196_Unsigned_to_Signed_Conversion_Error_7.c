#include <stdio.h>
#include <limits.h>

void risky_function(unsigned int length) {
    int signed_length = (int) length;
    char buffer[10];

    if (signed_length >= 0 && signed_length < 10) {
        buffer[signed_length] = 'A';
        printf("Buffer index %d set successfully.\n", signed_length);
    } else {
        printf("Invalid buffer index: %d\n", signed_length);
    }
}

int main() {
    unsigned int large_value = UINT_MAX;
    risky_function(large_value);
    return 0;
}