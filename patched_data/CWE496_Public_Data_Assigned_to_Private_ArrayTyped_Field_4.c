#include <stdio.h>
#include <string.h>

typedef struct {
    int privateArray[5];
} DataHolder;

void assignPublicDataToPrivateArray(int *publicData, DataHolder *holder, size_t publicDataSize) {
    if (publicDataSize <= 5) {
        memcpy(holder->privateArray, publicData, publicDataSize * sizeof(int));
    } else {
        fprintf(stderr, "Error: publicData size exceeds privateArray capacity.\n");
    }
}

int main() {
    DataHolder holder;
    int publicData[5] = {1, 2, 3, 4, 5};
    assignPublicDataToPrivateArray(publicData, &holder, sizeof(publicData) / sizeof(publicData[0]));
    return 0;
}