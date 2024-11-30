#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t length;
} IntArray;

IntArray* cloneMutableData(IntArray *data) {
    IntArray *clone = malloc(sizeof(IntArray));
    clone->length = data->length;
    clone->array = malloc(clone->length * sizeof(int));
    memcpy(clone->array, data->array, clone->length * sizeof(int));
    return clone;
}

IntArray* getArray(IntArray *data) {
    return cloneMutableData(data);
}

int main() {
    IntArray original;
    original.length = 5;
    original.array = malloc(original.length * sizeof(int));
    for (size_t i = 0; i < original.length; i++) {
        original.array[i] = i;
    }

    IntArray *result = getArray(&original);

    for (size_t i = 0; i < result->length; i++) {
        printf("%d ", result->array[i]);
    }
    printf("\n");

    free(original.array);
    free(result->array);
    free(result);
    
    return 0;
}