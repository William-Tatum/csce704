#include <stdio.h>
#include <string.h>

void readBuffer(const char *buffer, size_t size, int offset) {
    if (offset < 0 || offset >= size) {
        printf("Error: Read position outside the buffer\n");
        return;
    }
    printf("Character at position %d: %c\n", offset, buffer[offset]);
}

int main() {
    char data[10] = "ABCDEFGHI";
    int position = 0;
    printf("Enter a position to read (0-%zu): ", sizeof(data) - 1);
    if (scanf("%d", &position) != 1 || position < 0 || position >= sizeof(data)) {
        printf("Invalid input. Please enter a number between 0 and %zu.\n", sizeof(data) - 1);
    } else {
        readBuffer(data, sizeof(data), position);
    }
    return 0;
}