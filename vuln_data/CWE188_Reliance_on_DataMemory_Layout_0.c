#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char header[4];
    int data;
    char footer[4];
} PackedProtocol;
#pragma pack(pop)

int main() {
    char buffer[12];
    memset(buffer, 0, sizeof(buffer));
    memcpy(buffer, "HDR", 3);
    memcpy(buffer + 4, "FTR", 3);

    PackedProtocol *protoPtr = (PackedProtocol *)buffer;
    
    if (strncmp(protoPtr->header, "HDR", 3) == 0) {
        printf("Header is correct\n");
    }
    
    if (strncmp(protoPtr->footer, "FTR", 3) == 0) {
        printf("Footer is correct\n");
    }
    
    return 0;
}