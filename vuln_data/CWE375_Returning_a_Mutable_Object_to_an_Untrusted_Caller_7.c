#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
} MutableData;

MutableData* getMutableDataInstance() {
    MutableData *md = (MutableData*)malloc(sizeof(MutableData));
    if (!md) return NULL;
    md->data = strdup("Sensitive Information");
    return md;
}

MutableData* getCloneOfMutableData(MutableData *original) {
    if (!original) return NULL;
    MutableData *clone = (MutableData*)malloc(sizeof(MutableData));
    if (!clone) return NULL;
    clone->data = strdup(original->data);
    return clone;
}

MutableData* provideProtectedData() {
    MutableData *original = getMutableDataInstance();
    if (!original) return NULL;
    MutableData *clone = getCloneOfMutableData(original);
    free(original->data);
    free(original);
    return clone;
}

void cleanUp(MutableData *md) {
    if (md) {
        free(md->data);
        free(md);
    }
}

int main() {
    MutableData *safeData = provideProtectedData();
    if (safeData) {
        printf("Received Data: %s\n", safeData->data);
        cleanUp(safeData);
    }
    return 0;
}