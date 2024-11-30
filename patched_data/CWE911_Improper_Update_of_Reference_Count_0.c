#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int ref_count;
} Resource;

void acquire_resource(Resource *res) {
    if (res) {
        res->ref_count++;
    }
}

void release_resource(Resource *res) {
    if (res && res->ref_count > 0) {
        res->ref_count--;
        if (res->ref_count == 0) {
            free(res->data);
            res->data = NULL;
        }
    }
}

int main() {
    Resource res;
    res.data = (int *)malloc(sizeof(int) * 10);
    if (!res.data) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    res.ref_count = 1;

    acquire_resource(&res);
    release_resource(&res);
    release_resource(&res);

    if (res.data != NULL) {
        release_resource(&res);
    }

    return 0;
}