#include <stdio.h>
#include <string.h>

void copyData(char *source) {
    char buffer[10];
    strncpy(buffer, source, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Copied data: %s\n", buffer);
}

int main() {
    char data[] = "This string is too long for the buffer!";
    copyData(data);
    return 0;
}