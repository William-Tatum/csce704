#include <stdio.h>
#include <limits.h>

void process_value(unsigned int uval) {
    int sval;

    if (uval > INT_MAX) {
        printf("Error: Unsigned value too large to be converted to signed.\n");
        return;
    }

    sval = (int)uval;
    printf("Processed signed value: %d\n", sval);
}

int main() {
    unsigned int uval = 3000000000; // Example large unsigned value
    process_value(uval);
    return 0;
}