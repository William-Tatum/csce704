#include <stdio.h>
#include <string.h>

typedef struct {
    char privateData[100];
} SecureContainer;

void assignPublicData(SecureContainer* container, const char* publicData) {
    if (publicData && strlen(publicData) < sizeof(container->privateData)) {
        strncpy(container->privateData, publicData, sizeof(container->privateData) - 1);
        container->privateData[sizeof(container->privateData) - 1] = '\0';
    } else {
        printf("Error: Data too large to assign to private array or publicData is NULL.\n");
    }
}

void printData(SecureContainer* container) {
    printf("Data: %s\n", container->privateData);
}

int main() {
    SecureContainer container = {0};
    const char* publicData = "This is public data";
    assignPublicData(&container, publicData);
    printData(&container);
    return 0;
}