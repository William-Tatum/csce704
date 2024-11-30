#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strncpy(buffer, "123456789", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    int index = 9;
    char c = buffer[index];

    printf("Character at index %d: %c\n", index, c);
    return 0;
}