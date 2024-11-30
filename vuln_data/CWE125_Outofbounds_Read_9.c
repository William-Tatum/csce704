#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "HelloWorld");
    printf("Buffer content: %s\n", buffer);
    int index = 15; // Out-of-bounds index
    char c = buffer[index]; // Attempt to read out-of-bounds
    printf("Character at index %d: %c\n", index, c);
    return 0;
}