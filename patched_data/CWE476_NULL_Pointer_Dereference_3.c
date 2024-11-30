#include <stdio.h>

void processValue(int *ptr) {
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
    } else {
        printf("Pointer is NULL\n");
    }
}

int main() {
    int *ptr = NULL;
    processValue(ptr);
    return 0;
}