#include <stdio.h>
#include <string.h>

typedef struct {
    int privateArray[5];
} PrivateData;

void assignData(PrivateData *pd, int *publicData, size_t size) {
    if (size > sizeof(pd->privateArray) / sizeof(pd->privateArray[0])) {
        size = sizeof(pd->privateArray) / sizeof(pd->privateArray[0]);
    }
    memcpy(pd->privateArray, publicData, size * sizeof(int));
}

int main() {
    int publicData[] = {1, 2, 3, 4, 5};
    PrivateData pd;
    assignData(&pd, publicData, sizeof(publicData) / sizeof(publicData[0]));
    return 0;
}