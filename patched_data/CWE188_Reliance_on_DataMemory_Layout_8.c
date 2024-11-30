#include <stdio.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t length;
    char payload[100];
} ProtocolPacket;
#pragma pack(pop)

void processPacket(char *data) {
    ProtocolPacket *packet = (ProtocolPacket *)data;

    if (packet->length > sizeof(packet->payload)) {
        printf("Packet length exceeds buffer size, rejecting packet.\n");
        return;
    }

    if (packet->type == 1) {
        printf("Processing type 1 packet with payload: %.*s\n", packet->length, packet->payload);
    } else if (packet->type == 2) {
        printf("Processing type 2 packet with length: %u\n", packet->length);
    } else {
        printf("Unknown packet type: %u\n", packet->type);
    }
}

int main() {
    char rawData[sizeof(ProtocolPacket)] = {0};
    strncpy(rawData + 6, "Hello, World!", sizeof(ProtocolPacket) - 6);
    *(uint16_t *)rawData = 1;
    *(uint32_t *)(rawData + 2) = strnlen(rawData + 6, sizeof(((ProtocolPacket *)0)->payload));
    processPacket(rawData);
    return 0;
}