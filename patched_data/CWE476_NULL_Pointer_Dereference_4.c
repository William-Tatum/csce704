#include <stdio.h>
#include <stdlib.h>

void process(int *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Error: Null pointer passed to process function.\n");
        exit(EXIT_FAILURE);
    }
    printf("Processing value: %d\n", *ptr);
}

int main() {
    int value = 0;
    int *data = &value;
    process(data);
    return 0;
}