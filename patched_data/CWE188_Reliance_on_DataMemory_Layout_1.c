#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char header[4];
    int data;
} PacketV1;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
    short length;
    char header[4];
    int data;
} PacketV2;
#pragma pack(pop)

void processPacket(const char *buffer, size_t size) {
    if (buffer == NULL) {
        printf("Invalid packet\n");
        return;
    }
    
    if (size == sizeof(PacketV1)) {
        const PacketV1 *pktV1 = (const PacketV1 *)buffer;
        printf("PacketV1 Data: %d\n", pktV1->data);
    } else if (size == sizeof(PacketV2)) {
        const PacketV2 *pktV2 = (const PacketV2 *)buffer;
        printf("PacketV2 Data: %d, Length: %d\n", pktV2->data, pktV2->length);
    } else {
        printf("Unknown packet format\n");
    }
}

int main() {
    char buffer[sizeof(PacketV1)];
    memset(buffer, 0, sizeof(buffer));
    PacketV1 *pkt = (PacketV1 *)buffer;
    strncpy(pkt->header, "HDR", sizeof(pkt->header) - 1);
    pkt->data = 42;

    processPacket(buffer, sizeof(PacketV1));

    return 0;
}