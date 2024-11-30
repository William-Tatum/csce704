#include <stdio.h>
#include <string.h>

typedef struct {
    char privateData[100];
} PrivateArray;

void exposeData(const char *publicData, size_t dataLen) {
    PrivateArray arrayObj;
    if (dataLen < sizeof(arrayObj.privateData)) {
        strncpy(arrayObj.privateData, publicData, sizeof(arrayObj.privateData) - 1);
        arrayObj.privateData[sizeof(arrayObj.privateData) - 1] = '\0';
        printf("Data assigned to private array: %s\n", arrayObj.privateData);
    } else {
        printf("Data too large to assign\n");
    }
}

int main() {
    const char publicData[] = "Sensitive Information";
    exposeData(publicData, strlen(publicData) + 1);
    return 0;
}