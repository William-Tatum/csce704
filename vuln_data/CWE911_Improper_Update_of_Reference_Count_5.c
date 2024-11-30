#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ref_count;
    char *data;
} Resource;

Resource* create_resource(const char *data) {
    Resource *res = (Resource *)malloc(sizeof(Resource));
    res->ref_count = 1;
    res->data = strdup(data);
    return res;
}

void use_resource(Resource *res) {
    if (res == NULL) return;
    printf("Using resource: %s\n", res->data);
}

void grab_resource(Resource *res) {
    if (res == NULL) return;
    res->ref_count++;
}

void release_resource(Resource *res) {
    if (res == NULL) return;
    if (--res->ref_count == 0) {
        free(res->data);
        free(res);
    }
}

int main() {
    Resource *res = create_resource("This is a resource");
    use_resource(res);
    grab_resource(res);
    release_resource(res);
    release_resource(res);
    return 0;
}