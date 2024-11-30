#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t length;
} IntArray;

IntArray* cloneMutableData(const IntArray *data) {
    if (!data || !data->array || data->length == 0) return NULL;

    IntArray *clone = malloc(sizeof(IntArray));
    if (!clone) return NULL;

    clone->length = data->length;
    clone->array = malloc(clone->length * sizeof(int));
    if (!clone->array) {
        free(clone);
        return NULL;
    }

    memcpy(clone->array, data->array, clone->length * sizeof(int));
    return clone;
}

IntArray* getArray(const IntArray *data) {
    return cloneMutableData(data);
}

int main() {
    IntArray original;
    original.length = 5;
    original.array = malloc(original.length * sizeof(int));
    if (!original.array) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < original.length; i++) {
        original.array[i] = i;
    }

    IntArray *result = getArray(&original);
    if (result) {
        for (size_t i = 0; i < result->length; i++) {
            printf("%d ", result->array[i]);
        }
        printf("\n");

        free(result->array);
        free(result);
    } else {
        fprintf(stderr, "Array cloning failed\n");
        free(original.array);
        return EXIT_FAILURE;
    }

    free(original.array);
    return EXIT_SUCCESS;
}