#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
} MutableArray;

MutableArray* getClonedArray(const MutableArray* original) {
    if (!original || !original->data) return NULL;
    
    MutableArray* clone = (MutableArray*)malloc(sizeof(MutableArray));
    if (!clone) return NULL;

    clone->size = original->size;
    clone->data = (int*)malloc(clone->size * sizeof(int));
    if (!clone->data) {
        free(clone);
        return NULL;
    }

    memcpy(clone->data, original->data, clone->size * sizeof(int));
    return clone;
}

void freeMutableArray(MutableArray* array) {
    if(array) {
        free(array->data);
        array->data = NULL;
        free(array);
    }
}

int main() {
    MutableArray original;
    size_t arraySize = 5;
    original.size = arraySize;
    original.data = (int*)malloc(arraySize * sizeof(int));
    if (!original.data) return 1;
    
    for(size_t i = 0; i < arraySize; ++i) {
        original.data[i] = i + 1;
    }
    
    MutableArray* cloned = getClonedArray(&original);
    if(cloned) {
        for(size_t i = 0; i < cloned->size; ++i) {
            printf("%d ", cloned->data[i]);
        }
        printf("\n");
        freeMutableArray(cloned);
    }
    
    free(original.data);
    original.data = NULL;

    return 0;
}