#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct ProtocolV1 {
    uint8_t header;
    uint8_t payload[10];
};

struct ProtocolV2 {
    uint16_t header;
    uint8_t padding;
    uint8_t payload[10];
};

void process_data(void *data, int version) {
    if (version == 1) {
        struct ProtocolV1 *pkt = (struct ProtocolV1 *)data;
        printf("V1 Header: %d\n", pkt->header);
        printf("V1 Payload: %.10s\n", pkt->payload);
    } else if (version == 2) {
        struct ProtocolV2 *pkt = (struct ProtocolV2 *)data;
        printf("V2 Header: %d\n", pkt->header);
        printf("V2 Payload: %.10s\n", pkt->payload);
    }
}

int main() {
    struct ProtocolV1 dataV1 = {65, "HelloV1"};
    struct ProtocolV2 dataV2 = {258, 0, "HelloV2"};
    
    process_data(&dataV1, 1);
    process_data(&dataV2, 2);
    
    return 0;
}