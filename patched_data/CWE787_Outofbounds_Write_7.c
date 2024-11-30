#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char *data = "This is a long string that exceeds buffer length";
    strncpy(buffer, data, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer: %s\n", buffer);
    return 0;
}