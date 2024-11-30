#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int ref_count;
} Resource;

Resource* create_resource() {
    Resource *res = (Resource*)malloc(sizeof(Resource));
    if (!res) {
        return NULL; // Handle memory allocation failure
    }
    res->data = (int*)malloc(sizeof(int)); // Simulating resource allocation
    if (!res->data) {
        free(res); // Cleanly exit on failure
        return NULL;
    }
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
        if (res->ref_count == 0 && res->data != NULL) {
            free(res->data);
            res->data = NULL; // Nullify pointer after freeing
            free(res);
        }
    }
}

int main() {
    Resource *res1 = create_resource();
    if (res1 == NULL) {
        return 1; // Exit if resource creation failed
    }
    increment_ref_count(res1);
    decrement_ref_count(res1);
    decrement_ref_count(res1);
    return 0;
}