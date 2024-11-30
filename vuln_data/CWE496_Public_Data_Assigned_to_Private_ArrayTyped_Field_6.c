#include <stdio.h>
#include <string.h>

typedef struct {
    char privateData[100];
} SecureContainer;

void assignPublicData(SecureContainer* container, const char* publicData) {
    if (strlen(publicData) < sizeof(container->privateData)) {
        strcpy(container->privateData, publicData);
    } else {
        printf("Error: Data too large to assign to private array.\n");
    }
}

void printData(SecureContainer* container) {
    printf("Data: %s\n", container->privateData);
}

int main() {
    SecureContainer container;
    const char* publicData = "This is public data";
    assignPublicData(&container, publicData);
    printData(&container);
    return 0;
}