#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *data = malloc(4);
    if (data == NULL) {
        return 1;
    }
    strcpy(data, "123");

    int *intPtr = (int *)data;
    printf("Interpreted as int: %d\n", *intPtr);

    free(data);
    return 0;
}