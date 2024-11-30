#include <stdio.h>
#include <string.h>

void modifyData(char *data) {
    strncpy(data, "Modified Data", 99);
    data[99] = '\0';
}

void sendData(const char *data) {
    char dataCopy[100];
    strncpy(dataCopy, data, 99);
    dataCopy[99] = '\0';
    modifyData(dataCopy);
    printf("Sent data: %s\n", dataCopy);
}

int main() {
    char originalData[100] = "Original Data";
    sendData(originalData);
    printf("Original data remains unchanged: %s\n", originalData);
    return 0;
}