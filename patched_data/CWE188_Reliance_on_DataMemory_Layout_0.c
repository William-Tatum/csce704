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
    char buffer[sizeof(PackedProtocol)];
    memset(buffer, 0, sizeof(buffer));
    
    PackedProtocol *protoPtr = (PackedProtocol *)buffer;
    strncpy(protoPtr->header, "HDR", sizeof(protoPtr->header) - 1);
    strncpy(protoPtr->footer, "FTR", sizeof(protoPtr->footer) - 1);

    if (strncmp(protoPtr->header, "HDR", sizeof(protoPtr->header) - 1) == 0) {
        printf("Header is correct\n");
    }
    
    if (strncmp(protoPtr->footer, "FTR", sizeof(protoPtr->footer) - 1) == 0) {
        printf("Footer is correct\n");
    }
    
    return 0;
}