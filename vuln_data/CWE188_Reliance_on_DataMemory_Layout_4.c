#include <stdio.h>
#include <string.h>

typedef struct {
    int field1;
    int field2;
} PacketV1;

typedef struct {
    int field1;
    int field3;
    int field2;
} PacketV2;

void processPacket(void *packet, int version) {
    if (version == 1) {
        PacketV1 *pkt = (PacketV1 *)packet;
        printf("V1: Field1 = %d, Field2 = %d\n", pkt->field1, pkt->field2);
    } else if (version == 2) {
        PacketV2 *pkt = (PacketV2 *)packet;
        printf("V2: Field1 = %d, Field2 = %d, Field3 = %d\n", pkt->field1, pkt->field2, pkt->field3);
    }
}

int main() {
    PacketV1 packet1 = {100, 200};
    PacketV2 packet2 = {300, 400, 500};
    processPacket(&packet1, 1);
    processPacket(&packet2, 2);
    return 0;
}