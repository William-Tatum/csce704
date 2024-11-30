#include <stdio.h>
#include <string.h>

void readBufferOverRead() {
    char source[] = "SensitiveData";
    char destination[8];
    strncpy(destination, source, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';
    printf("Content: %s\n", destination);
}

int main() {
    readBufferOverRead();
    return 0;
}