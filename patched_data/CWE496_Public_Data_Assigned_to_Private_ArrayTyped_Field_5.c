#include <stdio.h>
#include <string.h>

typedef struct {
    char privateArray[10];
} PrivateArray;

void assignPublicData(PrivateArray *obj, const char *publicData) {
    strncpy(obj->privateArray, publicData, sizeof(obj->privateArray) - 1);
    obj->privateArray[sizeof(obj->privateArray) - 1] = '\0';
}

void printArray(const PrivateArray *obj) {
    printf("Array content: %s\n", obj->privateArray);
}

int main() {
    PrivateArray obj;
    const char *data = "public";
    assignPublicData(&obj, data);
    printArray(&obj);
    return 0;
}