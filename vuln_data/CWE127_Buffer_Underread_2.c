#include <stdio.h>
#include <string.h>

void readBuffer(char *buffer, size_t size, int offset) {
    if (offset < 0 || offset >= size) {
        printf("Error: Read position outside the buffer\n");
        return;
    }
    printf("Character at position %d: %c\n", offset, buffer[offset]);
}

int main() {
    char data[10] = "ABCDEFGHI";
    int position = -1;
    readBuffer(data, sizeof(data), position);
    return 0;
}