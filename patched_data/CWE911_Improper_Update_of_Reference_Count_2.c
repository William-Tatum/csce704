#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int refCount;
    char *data;
} Resource;

Resource* createResource() {
    Resource *res = (Resource*)malloc(sizeof(Resource));
    if (res) {
        res->refCount = 1;
        res->data = malloc(100); // arbitrary data allocation
        if (!res->data) {
            free(res); 
            return NULL;
        }
    }
    return res;
}

void retainResource(Resource *res) {
    if (res) {
        res->refCount++;
    }
}

void releaseResource(Resource *res) {
    if (res) {
        res->refCount--;
        if (res->refCount <= 0) {
            free(res->data);
            free(res);
        }
    }
}

int main() {
    Resource *res = createResource();
    if (!res) {
        fprintf(stderr, "Failed to create resource\n");
        return 1;
    }

    retainResource(res);

    // Proper handling of refCount
    releaseResource(res); // Reduce count to initial
    releaseResource(res); // Properly release the Resource

    return 0;
}