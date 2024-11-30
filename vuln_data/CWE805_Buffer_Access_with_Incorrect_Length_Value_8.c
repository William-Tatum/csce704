#include <stdio.h>
#include <string.h>

void copyData(char *src, int len) {
    char buffer[10];
    if (len > sizeof(buffer)) {
        printf("Error: Length exceeds buffer size\n");
        return;
    }
    memcpy(buffer, src, len);
    printf("Data copied: %s\n", buffer);
}

int main() {
    char *data = "Hello, CWE-805!";
    copyData(data, 15);
    return 0;
}