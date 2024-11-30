#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ref_count;
    char *data;
} Resource;

Resource* create_resource(const char *data) {
    if (data == NULL) return NULL;
    Resource *res = (Resource *)malloc(sizeof(Resource));
    if (res == NULL) return NULL; // Check for malloc failure
    res->data = strdup(data);
    if (res->data == NULL) { // Check if strdup failed
        free(res);
        return NULL;
    }
    res->ref_count = 1;
    return res;
}

void use_resource(Resource *res) {
    if (res == NULL || res->data == NULL) return;
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
    if (res == NULL) {
        fprintf(stderr, "Failed to create resource\n");
        return EXIT_FAILURE;
    }
    use_resource(res);
    grab_resource(res);
    release_resource(res);
    release_resource(res);
    return 0;
}