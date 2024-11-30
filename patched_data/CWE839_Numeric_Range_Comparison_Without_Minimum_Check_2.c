#include <stdio.h>
#include <limits.h>

int main() {
    int value;
    const int MAX_VALUE = 100;
    const int MIN_VALUE = 0;

    printf("Enter a value between %d and %d: ", MIN_VALUE, MAX_VALUE);

    // Use a character buffer to securely read input
    char input_buffer[20];
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Securely parse the input and check for range and overflow
    char *endptr;
    long input_value = strtol(input_buffer, &endptr, 10);

    if (endptr == input_buffer || *endptr != '\n' && *endptr != '\0' || input_value < INT_MIN || input_value > INT_MAX || input_value < MIN_VALUE || input_value > MAX_VALUE) {
        printf("Error: Invalid or out of range value.\n");
        return 1;
    }

    value = (int)input_value;
    printf("Valid value: %d\n", value);

    return 0;
}