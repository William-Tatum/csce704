#include <stdio.h>
#include <string.h>

void readBuffer(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer));

    for (int i = 0; i <= 10; i++) {
        printf("%c\n", buffer[i]);
    }
}

int main() {
    const char *data = "123456789012345";
    readBuffer(data);
    return 0;
}