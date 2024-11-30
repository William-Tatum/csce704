#include <stdio.h>
#include <stdlib.h>

void processData(int *data) {
    if (data == NULL) {
        printf("Error: NULL pointer dereference attempt avoided.\n");
        return;
    }
    printf("Processing data: %d\n", *data);
}

int main() {
    int *ptr = NULL;
    processData(ptr);
    return 0;
}