#include <stdio.h>
#include <string.h>

void copyData(char *source) {
    char buffer[10];
    strcpy(buffer, source); // Potential buffer overflow if source is larger than buffer
    printf("Copied data: %s\n", buffer);
}

int main() {
    char data[] = "This string is too long for the buffer!";
    copyData(data);
    return 0;
}