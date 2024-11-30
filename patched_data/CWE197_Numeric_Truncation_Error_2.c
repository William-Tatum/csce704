#include <stdio.h>
#include <limits.h>

void processValue(int largeValue) {
    short truncatedValue;
    if (largeValue > SHRT_MAX || largeValue < SHRT_MIN) {
        printf("Error: Value out of range for a short\n");
        return;
    }
    truncatedValue = (short)largeValue;
    printf("Processed value: %d\n", truncatedValue);
}

int main() {
    int largeValue = 70000;
    processValue(largeValue);
    return 0;
}