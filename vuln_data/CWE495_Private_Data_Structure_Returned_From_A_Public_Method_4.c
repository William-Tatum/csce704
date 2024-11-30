#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int data;
} PrivateData;

typedef struct {
    PrivateData *privateData;
} PublicInterface;

PrivateData* getPrivateData(PublicInterface *pubIntf) {
    return pubIntf->privateData;
}

int main() {
    PublicInterface pubIntf;
    PrivateData privateData;
    privateData.data = 42;
    pubIntf.privateData = &privateData;

    PrivateData *leakedData = getPrivateData(&pubIntf);
    printf("Data before modification: %d\n", leakedData->data);

    leakedData->data = 99;
    printf("Data after modification: %d\n", privateData.data);

    return 0;
}