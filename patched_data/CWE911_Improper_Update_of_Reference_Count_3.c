#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int count;
    char *data;
} Resource;

void acquireResource(Resource *res) {
    if (res == NULL) return;
    res->count++;
}

void releaseResource(Resource *res) {
    if (res == NULL) return;
    if (res->count > 0) {
        res->count--;
        if (res->count == 0) {
            free(res->data);
            res->data = NULL;
        }
    }
}

int main() {
    Resource *res = (Resource *)malloc(sizeof(Resource));
    if (res == NULL) {
        fprintf(stderr, "Allocation failed for Resource\n");
        exit(EXIT_FAILURE);
    }
    res->data = (char *)malloc(100 * sizeof(char));
    if (res->data == NULL) {
        fprintf(stderr, "Allocation failed for Resource data\n");
        free(res);
        exit(EXIT_FAILURE);
    }
    res->count = 0;

    acquireResource(res);
    acquireResource(res);

    releaseResource(res);
    releaseResource(res);

    if (res->data != NULL) {
        free(res->data);
    }
    free(res);
    return 0;
}