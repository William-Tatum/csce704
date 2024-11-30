#include <stdio.h>
#include <string.h>

void copyData(char *src, int len) {
    char buffer[10];
    if (len >= sizeof(buffer)) {
        printf("Error: Length exceeds buffer size\n");
        return;
    }
    strncpy(buffer, src, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // ensure null-termination
    printf("Data copied: %s\n", buffer);
}

int main() {
    char *data = "Hello, CWE-805!";
    copyData(data, strlen(data));
    return 0;
}