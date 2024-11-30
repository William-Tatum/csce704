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
    if (!md->data) {
        free(md);
        return NULL;
    }
    return md;
}

MutableData* getCloneOfMutableData(MutableData *original) {
    if (!original || !original->data) return NULL;
    MutableData *clone = (MutableData*)malloc(sizeof(MutableData));
    if (!clone) return NULL;
    clone->data = strdup(original->data);
    if (!clone->data) {
        free(clone);
        return NULL;
    }
    return clone;
}

MutableData* provideProtectedData() {
    MutableData *original = getMutableDataInstance();
    if (!original) return NULL;
    MutableData *clone = getCloneOfMutableData(original);
    cleanUp(original);
    return clone;
}

void cleanUp(MutableData *md) {
    if (md) {
        free(md->data);
        md->data = NULL;
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