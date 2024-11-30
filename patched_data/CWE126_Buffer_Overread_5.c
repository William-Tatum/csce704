#include <stdio.h>
#include <string.h>

void readBuffer(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    for (int i = 0; i < sizeof(buffer) && buffer[i] != '\0'; i++) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    const char *data = "123456789012345";
    readBuffer(data);
    return 0;
}