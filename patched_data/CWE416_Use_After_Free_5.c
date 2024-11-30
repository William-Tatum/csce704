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
    data = NULL;

    int *newData = (int *)malloc(sizeof(int) * 10);
    if (newData != NULL) {
        for (int i = 0; i < 10; i++) {
            newData[i] = i + 10;
        }
    }

    printf("Accessing valid memory: %d\n", newData[0]);

    free(newData);
    newData = NULL;

    return 0;
}