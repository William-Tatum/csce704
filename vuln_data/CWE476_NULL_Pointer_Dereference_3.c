#include <stdio.h>

void processValue(int *ptr) {
    printf("Value: %d\n", *ptr); // Potential NULL pointer dereference
}

int main() {
    int *ptr = NULL;
    processValue(ptr);
    return 0;
}