#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "Hello");
    int index = -1; // Vulnerability: Under-read with negative index

    // Attempt to read from a position before the buffer
    printf("Read character: %c\n", buffer[index]);

    return 0;
}