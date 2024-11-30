#include <stdio.h>
#include <string.h>

int main() {
    char buffer[15];
    char *bufPtr = buffer;
    strncpy(bufPtr, "Example", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
    return 0;
}