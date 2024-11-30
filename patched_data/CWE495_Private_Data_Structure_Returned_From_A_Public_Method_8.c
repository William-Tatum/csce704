#include <stddef.h>

struct PrivateData {
    int value;
};

struct PrivateData private_data_instance;

struct PrivateData* getPrivateData() {
    return NULL; // Do not expose the private data instance
}

void setPrivateData(int value) {
    private_data_instance.value = value;
}

int getPrivateDataValue() {
    return private_data_instance.value;
}