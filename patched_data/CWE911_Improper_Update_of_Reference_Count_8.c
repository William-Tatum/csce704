#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int ref_count;
} Resource;

Resource* create_resource(int data) {
    Resource* res = (Resource*)malloc(sizeof(Resource));
    if (res) {
        res->data = data;
        res->ref_count = 1;
    }
    return res;
}

void increase_ref(Resource* res) {
    if (res) {
        res->ref_count++;
    }
}

void decrease_ref(Resource* res) {
    if (res) {
        if (res->ref_count > 0) {
            res->ref_count--;
            if (res->ref_count == 0) {
                free(res);
            }
        }
    }
}

int main() {
    Resource* res = create_resource(42);
    if (res == NULL) {
        return 1;
    }
    increase_ref(res);
    decrease_ref(res);
    decrease_ref(res);
    return 0;
}