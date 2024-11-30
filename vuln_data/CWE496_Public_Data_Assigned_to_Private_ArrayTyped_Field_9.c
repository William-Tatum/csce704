#include <stdio.h>
#include <string.h>

struct VulnerableStruct {
    char private_array[10];
};

void assignData(struct VulnerableStruct* vs, const char* data) {
    if (vs == NULL || data == NULL) return;
    strcpy(vs->private_array, data);
}

int main() {
    struct VulnerableStruct vs;
    const char* publicData = "publicdata";
    assignData(&vs, publicData);
    printf("%s\n", vs.private_array);
    return 0;
}