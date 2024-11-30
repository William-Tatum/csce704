#include <stdio.h>
#include <string.h>

void readBuffer(char *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", buffer[i]);
    }
}

int main() {
    char data[] = "SensitiveData123";
    int bufferSize = strlen(data);
    readBuffer(data, bufferSize);
    return 0;
}