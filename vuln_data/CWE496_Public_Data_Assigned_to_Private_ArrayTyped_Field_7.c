#include <stdio.h>
#include <string.h>

typedef struct {
    char privateData[100];
} PrivateArray;

void exposeData(char *publicData, size_t dataLen) {
    PrivateArray arrayObj;
    if (dataLen < sizeof(arrayObj.privateData)) {
        strcpy(arrayObj.privateData, publicData);
        printf("Data assigned to private array: %s\n", arrayObj.privateData);
    } else {
        printf("Data too large to assign\n");
    }
}

int main() {
    char publicData[] = "Sensitive Information";
    exposeData(publicData, sizeof(publicData));
    return 0;
}