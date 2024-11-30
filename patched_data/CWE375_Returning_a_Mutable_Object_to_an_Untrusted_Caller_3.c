#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
} MutableData;

MutableData* cloneMutableData(MutableData *original) {
    if (original == NULL || original->data == NULL) return NULL;
    
    MutableData *clone = (MutableData *)malloc(sizeof(MutableData));
    if (clone == NULL) {
        perror("Failed to allocate memory for clone");
        exit(1);
    }
    
    clone->data = (char *)malloc(strlen(original->data) + 1);
    if (clone->data == NULL) {
        perror("Failed to allocate memory for clone data");
        free(clone);
        exit(1);
    }
    
    strcpy(clone->data, original->data);
    return clone;
}

MutableData* safeGetMutableData(MutableData *original) {
    return cloneMutableData(original);
}

int main() {
    MutableData original;
    original.data = "Sensitive Information";
    MutableData *safeCopy = safeGetMutableData(&original);
    if (safeCopy != NULL) {
        printf("Safe Copy Data: %s\n", safeCopy->data);
        free(safeCopy->data);
        free(safeCopy);
    } else {
        fprintf(stderr, "Failed to create a safe copy\n");
    }
    return 0;
}