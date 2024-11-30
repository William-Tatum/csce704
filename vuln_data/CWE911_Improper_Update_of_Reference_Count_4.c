#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int ref_count;
} Resource;

Resource* create_resource() {
    Resource *res = (Resource*)malloc(sizeof(Resource));
    res->data = (int*)malloc(sizeof(int)); // Simulating resource allocation
    res->ref_count = 1;
    return res;
}

void increment_ref_count(Resource *res) {
    if (res) {
        res->ref_count++;
    }
}

void decrement_ref_count(Resource *res) {
    if (res && res->ref_count > 0) {
        res->ref_count--;
        if (res->ref_count == 0) {
            free(res->data);
            free(res);
        }
    }
}

int main() {
    Resource *res1 = create_resource();
    increment_ref_count(res1);
    // Incorrect decrement, missing a call to correctly manage references
    decrement_ref_count(res1);
    decrement_ref_count(res1);
    return 0;
}