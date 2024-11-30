#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) {
        return -1;
    }

    strcpy(data, "Sample data");
    printf("Data: %s\n", data);

    free(data);

    char *newData = (char *)malloc(50 * sizeof(char));
    if (newData == NULL) {
        return -1;
    }

    strcpy(newData, "New data");
    printf("New Data: %s\n", newData);

    printf("Data after free: %s\n", data);

    free(newData);

    return 0;
}