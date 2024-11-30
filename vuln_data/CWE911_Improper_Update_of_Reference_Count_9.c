#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int ref_count;
} Resource;

Resource* acquire_resource() {
    Resource* res = (Resource*)malloc(sizeof(Resource));
    if (res) {
        res->data = 42;
        res->ref_count = 1; 
    }
    return res;
}

void add_reference(Resource* res) {
    if (res) {
        res->ref_count++;
    }
}

void release_reference(Resource* res) {
    if (res && --res->ref_count == 0) {
        free(res);
    }
}

int main() {
    Resource* res = acquire_resource();
    if (!res) {
        return 1;
    }

    add_reference(res);
    release_reference(res);
    release_reference(res);

    return 0;
}