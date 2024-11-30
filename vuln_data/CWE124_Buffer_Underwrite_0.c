#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char *bufPtr = buffer + 5;
    bufPtr -= 7;
    strcpy(bufPtr, "Example");
    printf("Buffer content: %s\n", buffer);
    return 0;
}