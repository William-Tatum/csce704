#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strncpy(buffer, "123456789012345", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
    return 0;
}