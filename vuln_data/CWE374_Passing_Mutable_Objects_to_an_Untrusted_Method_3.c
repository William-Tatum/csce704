#include <stdio.h>
#include <string.h>

void modifyData(char *data) {
    strcpy(data, "Modified Data");
}

void sendData(char *data) {
    char dataCopy[100];
    strcpy(dataCopy, data);
    modifyData(dataCopy);
    printf("Sent data: %s\n", dataCopy);
}

int main() {
    char originalData[100] = "Original Data";
    sendData(originalData);
    printf("Original data remains unchanged: %s\n", originalData);
    return 0;
}