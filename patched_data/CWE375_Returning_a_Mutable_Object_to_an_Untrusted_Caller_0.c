#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} MutableData;

MutableData* createMutableData(const char *input) {
    if(input == NULL) return NULL;
    MutableData *md = (MutableData *)malloc(sizeof(MutableData));
    if(md == NULL) return NULL;
    md->size = strlen(input);
    md->data = (char *)malloc(md->size + 1);
    if(md->data == NULL) {
        free(md);
        return NULL;
    }
    strcpy(md->data, input);
    return md;
}

MutableData* getClonedMutableData(MutableData *original) {
    if(original == NULL || original->data == NULL) return NULL;
    MutableData *clone = (MutableData *)malloc(sizeof(MutableData));
    if(clone == NULL) return NULL;
    clone->size = original->size;
    clone->data = (char *)malloc(clone->size + 1);
    if(clone->data == NULL) {
        free(clone);
        return NULL;
    }
    strcpy(clone->data, original->data);
    return clone;
}

int main() {
    MutableData *original = createMutableData("SensitiveInfo");
    if(original == NULL || original->data == NULL) {
        fprintf(stderr, "Failed to create original data.\n");
        return 1;
    }
    
    MutableData *cloned = getClonedMutableData(original);
    if(cloned == NULL || cloned->data == NULL) {
        fprintf(stderr, "Failed to clone data.\n");
        if(original != NULL) {
            free(original->data);
            free(original);
        }
        return 1;
    }
    
    printf("Original Data: %s\n", original->data);
    printf("Cloned Data: %s\n", cloned->data);
    
    free(original->data);
    free(original);
    free(cloned->data);
    free(cloned);
    
    return 0;
}