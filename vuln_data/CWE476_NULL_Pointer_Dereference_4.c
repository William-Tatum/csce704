#include <stdio.h>
#include <stdlib.h>

void process(int *ptr) {
    printf("Processing value: %d\n", *ptr);
}

int main() {
    int *data = NULL;
    process(data);
    return 0;
}