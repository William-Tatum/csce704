struct DataContainer {
    char privateData[10];
};

void exposePrivateData(struct DataContainer *container, const char *publicData) {
    strncpy(container->privateData, publicData, sizeof(container->privateData) - 1);
    container->privateData[sizeof(container->privateData) - 1] = '\0';
}

#include <stdio.h>
int main() {
    struct DataContainer container;
    exposePrivateData(&container, "publicInfo");
    printf("%s\n", container.privateData);
    return 0;
}