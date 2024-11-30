#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int ref_count;
} Resource;

Resource* create_resource(int value) {
    Resource* res = (Resource*)malloc(sizeof(Resource));
    if (!res) return NULL;
    res->data = value;
    res->ref_count = 1;
    return res;
}

void acquire_resource(Resource* res) {
    if (res) {
        res->ref_count++;
    }
}

void release_resource(Resource* res) {
    if (res) {
        res->ref_count--;
        if (res->ref_count == 0) {
            free(res);
        }
    }
}

int main() {
    Resource* res1 = create_resource(100);
    acquire_resource(res1);
    release_resource(res1);
    release_resource(res1);
    return 0;
}