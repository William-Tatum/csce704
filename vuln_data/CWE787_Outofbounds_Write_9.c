#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *data = "This string is definitely too long for the buffer";

    // Out-of-bounds write
    strcpy(buffer, data);

    printf("Buffer contains: %s\n", buffer);
    return 0;
}