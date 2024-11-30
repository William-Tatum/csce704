#include <stdio.h>

int main() {
    int large_number = 300;
    char truncated_value = (char)large_number;
    printf("Original value: %d\n", large_number);
    printf("Truncated value: %d\n", truncated_value);
    return 0;
}