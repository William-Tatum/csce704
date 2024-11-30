#include <stdio.h>
#include <string.h>

typedef struct {
    char sensitiveData[50];
} PrivateData;

void getSensitiveData(PrivateData *data) {
    strcpy(data->sensitiveData, "This is very sensitive");
}

int main() {
    PrivateData data;
    getSensitiveData(&data);
    printf("Sensitive Data: %s\n", data.sensitiveData);

    // No longer allowing external modification

    return 0;
}