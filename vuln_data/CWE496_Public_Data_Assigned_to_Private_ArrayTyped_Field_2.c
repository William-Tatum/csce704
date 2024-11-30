#include <stdio.h>
#include <string.h>

typedef struct {
    int privateData[10];
} VulnerableStruct;

void assignPublicData(int *publicData, int size, VulnerableStruct *vs) {
    if (size > 10) {
        printf("Too much data\n");
        return;
    }
    memcpy(vs->privateData, publicData, sizeof(int) * size);
}

int main() {
    int publicData[] = {1, 2, 3, 4, 5};
    VulnerableStruct vs;
    assignPublicData(publicData, 5, &vs);
    return 0;
}