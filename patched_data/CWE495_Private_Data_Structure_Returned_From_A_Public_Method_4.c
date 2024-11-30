#include <stdio.h>

typedef struct {
    int data;
} PrivateData;

typedef struct {
    PrivateData privateData;
} PublicInterface;

int getPrivateData(PublicInterface *pubIntf) {
    return pubIntf->privateData.data;
}

int main() {
    PublicInterface pubIntf;
    pubIntf.privateData.data = 42;

    int dataValue = getPrivateData(&pubIntf);
    printf("Data: %d\n", dataValue);

    return 0;
}