#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} MutableData;

MutableData* createMutableData(const char *input) {
    MutableData *md = (MutableData *)malloc(sizeof(MutableData));
    md->size = strlen(input);
    md->data = (char *)malloc(md->size + 1);
    strcpy(md->data, input);
    return md;
}

MutableData* getClonedMutableData(MutableData *original) {
    MutableData *clone = (MutableData *)malloc(sizeof(MutableData));
    clone->size = original->size;
    clone->data = (char *)malloc(clone->size + 1);
    strcpy(clone->data, original->data);
    return clone;
}

int main() {
    MutableData *original = createMutableData("SensitiveInfo");
    MutableData *cloned = getClonedMutableData(original);
    printf("Original Data: %s\n", original->data);
    printf("Cloned Data: %s\n", cloned->data);
    free(original->data);
    free(original);
    free(cloned->data);
    free(cloned);
    return 0;
}