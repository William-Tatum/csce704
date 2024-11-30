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
    res->count--;
    if (res->count == 0) {
        free(res->data);
        res->data = NULL;
    }
}

int main() {
    Resource *res = (Resource *)malloc(sizeof(Resource));
    res->data = (char *)malloc(100 * sizeof(char));
    res->count = 0;

    acquireResource(res);
    acquireResource(res);

    releaseResource(res);
    releaseResource(res);

    free(res);
    return 0;
}