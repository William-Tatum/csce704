#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char field1;
    int field2;
    char field3;
} PackedData;
#pragma pack(pop)

void processData(PackedData *data) {
    char buffer[10];
    strcpy(buffer, (char *)&data->field2);
    printf("Processed field: %s\n", buffer);
}

int main() {
    PackedData data = {'A', 1234, 'B'};
    processData(&data);
    return 0;
}