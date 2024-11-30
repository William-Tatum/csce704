#include <stdio.h>
#include <string.h>

void readBufferOverRead() {
    char source[] = "SensitiveData";
    char destination[8];
    for (int i = 0; i <= strlen(source); i++) {
        destination[i] = source[i]; // Buffer over-read occurs when i exceeds destination's size
    }
    printf("Content: %s\n", destination);
}

int main() {
    readBufferOverRead();
    return 0;
}