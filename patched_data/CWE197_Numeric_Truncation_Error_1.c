#include <stdio.h>

int main() {
    int large_number = 300;
    unsigned char truncated_value = (unsigned char)(large_number & 0xFF);
    printf("Original value: %d\n", large_number);
    printf("Truncated value: %u\n", truncated_value);
    return 0;
}