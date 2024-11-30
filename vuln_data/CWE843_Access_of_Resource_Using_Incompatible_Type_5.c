#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char info[8];
} Data;

int main() {
    void *resource;
    resource = malloc(sizeof(Data));
    
    if (resource == NULL) {
        return 1;
    }

    Point *p = (Point *)resource;
    p->x = 10;
    p->y = 20;

    printf("Point coordinates: %d, %d\n", p->x, p->y);

    Data *d = (Data *)resource;
    snprintf(d->info, sizeof(d->info), "Hello");
    
    printf("Data info: %s\n", d->info);

    free(resource);
    return 0;
}