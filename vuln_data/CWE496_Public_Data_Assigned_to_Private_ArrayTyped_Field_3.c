#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int privateArray[10];
} PrivateData;

void setPrivateArray(PrivateData *data, int *publicData, size_t length) {
    if (length <= 10) {
        memcpy(data->privateArray, publicData, length * sizeof(int));
    } else {
        printf("Error: Data exceeds private array size.\n");
    }
}

int main() {
    PrivateData myData;
    int publicData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    size_t length = sizeof(publicData) / sizeof(publicData[0]);

    setPrivateArray(&myData, publicData, length);

    for(int i = 0; i < 10; i++) {
        printf("%d ", myData.privateArray[i]);
    }
    printf("\n");

    return 0;
}