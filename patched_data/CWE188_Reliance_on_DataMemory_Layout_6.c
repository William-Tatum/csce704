#include <stdio.h>
#include <string.h>

#define HEADER_SIZE 8
#define NAME_OFFSET 12
#define NAME_LENGTH 10

typedef struct {
    char header[HEADER_SIZE];
    int integerField;
    char name[NAME_LENGTH];
} ProtocolPacket;

void processPacket(const char *packet, size_t packetSize) {
    if (packet == NULL || packetSize < NAME_OFFSET + NAME_LENGTH) return;

    char extractedName[NAME_LENGTH + 1];
    memcpy(extractedName, packet + NAME_OFFSET, NAME_LENGTH);
    extractedName[NAME_LENGTH] = '\0';

    printf("Extracted Name: %s\n", extractedName);
}

int main() {
    char packetData[32] = {0};

    ProtocolPacket pkt = {"HEADER__", 2020, "JohnDoe"};
    memcpy(packetData, &pkt, sizeof(pkt));

    processPacket(packetData, sizeof(packetData));
    return 0;
}