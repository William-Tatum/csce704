#include <stdio.h>
#include <stdlib.h>

void process(int *data, int size) {
    if (data == NULL) {
        fprintf(stderr, "Data is null\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        if (data[i] < 0) {
            fprintf(stderr, "Negative value encountered\n");
            free(data);
            exit(1);
        }
        data[i] *= 2;
    }
}

int main() {
    int *data = (int*)malloc(5 * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        data[i] = i + 1;
    }

    process(data, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", data[i]);
    }

    free(data);
    return 0;
}