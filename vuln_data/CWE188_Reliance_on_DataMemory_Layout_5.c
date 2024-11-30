#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char header;
    int data;
} PacketV1;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
    char header;
    short padding;
    int data;
} PacketV2;
#pragma pack(pop)

void processPacket(void *packet, int version) {
    if(version == 1) {
        PacketV1 *pkt = (PacketV1 *)packet;
        printf("Header: %c, Data: %d\n", pkt->header, pkt->data);
    } else if(version == 2) {
        PacketV2 *pkt = (PacketV2 *)packet;
        printf("Header: %c, Data: %d\n", pkt->header, pkt->data);
    } else {
        printf("Unsupported protocol version\n");
    }
}

int main() {
    char bufferV1[sizeof(PacketV1)];
    char bufferV2[sizeof(PacketV2)];

    PacketV1 *pkt1 = (PacketV1 *)bufferV1;
    pkt1->header = 'A';
    pkt1->data = 100;

    PacketV2 *pkt2 = (PacketV2 *)bufferV2;
    pkt2->header = 'B';
    pkt2->padding = 0;
    pkt2->data = 200;

    processPacket(bufferV1, 1);
    processPacket(bufferV2, 2);

    return 0;
}