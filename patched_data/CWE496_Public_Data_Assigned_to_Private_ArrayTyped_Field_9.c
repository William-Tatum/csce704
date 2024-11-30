#include <stdio.h>
#include <string.h>

struct VulnerableStruct {
    char private_array[10];
};

void assignData(struct VulnerableStruct* vs, const char* data) {
    if (vs == NULL || data == NULL) return;
    strncpy(vs->private_array, data, sizeof(vs->private_array) - 1);
    vs->private_array[sizeof(vs->private_array) - 1] = '\0';
}

int main() {
    struct VulnerableStruct vs;
    const char* publicData = "publicdata";
    assignData(&vs, publicData);
    printf("%s\n", vs.private_array);
    return 0;
}