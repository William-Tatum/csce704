#include <stdio.h>

void processValue(int largeValue) {
    short truncatedValue;
    if (largeValue > 32767 || largeValue < -32768) {
        printf("Error: Potential truncation\n");
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