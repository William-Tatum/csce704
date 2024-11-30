#include <stdio.h>
#include <string.h>

typedef struct {
    char privateData[50];
} DataContainer;

void assignPublicData(DataContainer *container, const char *data) {
    strcpy(container->privateData, data);
}

int main() {
    DataContainer container;
    const char *publicData = "Public Information";
    assignPublicData(&container, publicData);
    printf("Assigned to internal data: %s\n", container.privateData);
    return 0;
}