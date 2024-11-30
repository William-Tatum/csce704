#include <stdio.h>
#include <stdlib.h>

int main() {
    int *data = (int *)malloc(sizeof(int) * 10);
    if (data == NULL) {
        return 1;
    }
    
    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }

    free(data);

    if (data != NULL) {
        printf("Accessing freed memory: %d\n", data[0]);
    }

    int *newData = (int *)malloc(sizeof(int) * 10);
    if (newData != NULL) {
        for (int i = 0; i < 10; i++) {
            newData[i] = i + 10;
        }
    }

    if (data != NULL) {
        printf("Accessing reused freed memory: %d\n", data[0]);
    }

    free(newData);

    return 0;
}