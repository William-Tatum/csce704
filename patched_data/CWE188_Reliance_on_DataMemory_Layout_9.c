#include <stdio.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    short field1;
    char field2;
    int field3;
} PackedStruct;
#pragma pack()

typedef struct {
    short field1;
    char field2;
    int field3;
} UnpackedStruct;

int main() {
    PackedStruct packedData;
    UnpackedStruct unpackedData;

    char buffer[64];
    memset(buffer, 0, sizeof(buffer));

    packedData.field1 = 1;
    packedData.field2 = 'A';
    packedData.field3 = 100;

    unpackedData.field1 = 1;
    unpackedData.field2 = 'A';
    unpackedData.field3 = 100;

    if (sizeof(buffer) >= sizeof(packedData)) {
        memcpy(buffer, &packedData, sizeof(packedData));
        printf("Packed data: Field1=%d Field2=%c Field3=%d\n",
               ((PackedStruct*)buffer)->field1,
               ((PackedStruct*)buffer)->field2,
               ((PackedStruct*)buffer)->field3);
    }

    if (sizeof(buffer) >= sizeof(unpackedData)) {
        memcpy(buffer, &unpackedData, sizeof(unpackedData));
        printf("Unpacked data: Field1=%d Field2=%c Field3=%d\n",
               ((UnpackedStruct*)buffer)->field1,
               ((UnpackedStruct*)buffer)->field2,
               ((UnpackedStruct*)buffer)->field3);
    }

    return 0;
}