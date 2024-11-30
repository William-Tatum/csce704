#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int ref_count;
} Resource;

Resource* create_resource() {
    Resource *res = (Resource*)malloc(sizeof(Resource));
    if (!res) return NULL;
    res->data = (int*)malloc(sizeof(int) * 100);
    if (!res->data) {
        free(res);
        return NULL;
    }
    res->ref_count = 1;
    return res;
}

void retain_resource(Resource *res) {
    if (res) {
        res->ref_count++;
    }
}

void release_resource(Resource *res) {
    if (res && --res->ref_count == 0) {
        free(res->data);
        free(res);
    }
}

int main() {
    Resource *res1 = create_resource();
    if (!res1) {
        return 1;
    }
    
    retain_resource(res1);
    
    Resource *res2 = res1;
    
    release_resource(res1);
    
    release_resource(res2);
    
    return 0;
}