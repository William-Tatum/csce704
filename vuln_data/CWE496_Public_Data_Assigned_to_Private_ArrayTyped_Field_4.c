#include <stdio.h>
#include <string.h>

typedef struct {
    int privateArray[5];
} DataHolder;

void assignPublicDataToPrivateArray(int *publicData, DataHolder *holder) {
    memcpy(holder->privateArray, publicData, 5 * sizeof(int));
}

int main() {
    DataHolder holder;
    int publicData[5] = {1, 2, 3, 4, 5};
    assignPublicDataToPrivateArray(publicData, &holder);
    return 0;
}