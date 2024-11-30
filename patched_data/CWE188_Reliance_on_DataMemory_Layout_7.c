#include <stdio.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t header;
    uint32_t data1;
    uint16_t data2;
} ProtocolPacket;
#pragma pack(pop)

void processData(const uint8_t *packetData, size_t dataSize) {
    if (dataSize < sizeof(ProtocolPacket)) {
        fprintf(stderr, "Error: Packet data size is too small.\n");
        return;
    }
    const ProtocolPacket *packet = (const ProtocolPacket *)packetData;
    printf("Header: %u\n", packet->header);
    printf("Data1: %u\n", packet->data1);
    printf("Data2: %u\n", packet->data2);
}

int main() {
    uint8_t buffer[128] = {0};
    memcpy(buffer, "\x01\x02\x03\x04\x05\x06\x07\x08", 8);
    processData(buffer, sizeof(buffer));
    return 0;
}