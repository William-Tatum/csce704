#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int refCount;
    char *data;
} Resource;

Resource* createResource() {
    Resource *res = (Resource*)malloc(sizeof(Resource));
    if (res) {
        res->refCount = 0;
        res->data = malloc(100); // arbitrary data allocation
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
        if (res->refCount == 0) {
            free(res->data);
            free(res);
        }
    }
}

int main() {
    Resource *res = createResource();
    retainResource(res);

    // Incorrect handling of refCount
    releaseResource(res);
    // res->data is still being used, but refCount was improperly managed

    return 0;
}