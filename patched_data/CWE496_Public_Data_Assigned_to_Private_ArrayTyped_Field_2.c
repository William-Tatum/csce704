#include <stdio.h>
#include <string.h>

typedef struct {
    int privateData[10];
} SecureStruct;

void assignPublicData(const int *publicData, int size, SecureStruct *vs) {
    if (size > 10 || size < 0) {
        printf("Invalid data size\n");
        return;
    }
    memcpy(vs->privateData, publicData, sizeof(int) * size);
}

int main() {
    int publicData[] = {1, 2, 3, 4, 5};
    SecureStruct vs;
    assignPublicData(publicData, sizeof(publicData)/sizeof(publicData[0]), &vs);
    return 0;
}