#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int ref_count;
} Resource;

Resource* create_resource() {
    Resource *res = (Resource*)malloc(sizeof(Resource));
    if (res == NULL) {
        perror("Failed to allocate Resource");
        exit(EXIT_FAILURE);
    }
    res->data = (int*)malloc(sizeof(int));
    if (res->data == NULL) {
        perror("Failed to allocate data");
        free(res);
        exit(EXIT_FAILURE);
    }
    *(res->data) = 0;
    res->ref_count = 1;
    return res;
}

void retain_resource(Resource *res) {
    if (res) {
        res->ref_count++;
    }
}

void release_resource(Resource *res) {
    if (res) {
        res->ref_count--;
        if (res->ref_count == 0) {
            free(res->data);
            free(res);
            res = NULL;
        }
    }
}

int main() {
    Resource *res1 = create_resource();
    retain_resource(res1);

    Resource *res2 = res1;
    release_resource(res1);

    if (res2 && res2->ref_count > 0) {
        printf("Data: %d\n", *(res2->data));
    } else {
        printf("Resource has been released.\n");
    }

    release_resource(res2);
    return 0;
}