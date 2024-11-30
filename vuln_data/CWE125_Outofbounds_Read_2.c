#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "123456789");

    int index = 10;
    char c = buffer[index]; // Out-of-bounds read

    printf("Character at index %d: %c\n", index, c);
    return 0;
}