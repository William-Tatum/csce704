#include <stdio.h>
#include <string.h>

struct DataContainer {
    char privateData[10];
};

void exposePrivateData(struct DataContainer *container, const char *publicData) {
    size_t dataLen = strlen(publicData);
    if (dataLen >= sizeof(container->privateData)) {
        dataLen = sizeof(container->privateData) - 1;
    }
    strncpy(container->privateData, publicData, dataLen);
    container->privateData[dataLen] = '\0';
}

int main() {
    struct DataContainer container;
    exposePrivateData(&container, "publicInfo");
    printf("%s\n", container.privateData);
    return 0;
}