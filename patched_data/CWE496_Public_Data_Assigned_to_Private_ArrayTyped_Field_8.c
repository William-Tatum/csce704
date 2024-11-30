#include <stdio.h>
#include <string.h>

typedef struct {
    char privateData[50];
} DataContainer;

void assignPublicData(DataContainer *container, const char *data) {
    // Ensure the data fits within the buffer size to prevent overflow
    strncpy(container->privateData, data, sizeof(container->privateData) - 1);
    // Null-terminate the string
    container->privateData[sizeof(container->privateData) - 1] = '\0';
}

int main() {
    DataContainer container;
    const char *publicData = "Public Information";
    assignPublicData(&container, publicData);
    printf("Assigned to internal data: %s\n", container.privateData);
    return 0;
}