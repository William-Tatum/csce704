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

void processPacket(char *buffer, size_t size) {
    if (size == sizeof(PacketV1)) {
        PacketV1 *pktV1 = (PacketV1 *)buffer;
        printf("PacketV1 Data: %d\n", pktV1->data);
    } else if (size == sizeof(PacketV2)) {
        PacketV2 *pktV2 = (PacketV2 *)buffer;
        printf("PacketV2 Data: %d, Length: %d\n", pktV2->data, pktV2->length);
    } else {
        printf("Unknown packet format\n");
    }
}

int main() {
    char buffer[8];
    memset(buffer, 0, sizeof(buffer));
    PacketV1 *pkt = (PacketV1 *)buffer;
    strcpy(pkt->header, "HDR");
    pkt->data = 42;

    processPacket(buffer, sizeof(PacketV1));

    return 0;
}